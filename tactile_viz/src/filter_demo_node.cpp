/**
 * @file filter_demo_node.cpp
 * @brief Demo node to visualize filtering effects on tactile data
 *
 * This node collects tactile data for the first 6 points and resultant force,
 * applies filtering, and exports for visualization comparison.
 *
 * Filtering methods demonstrated:
 * 1. Raw data (no filter)
 * 2. Combined EMA + Slope filter (same as tactile_viz_node)
 */

#include <cmath>
#include <array>
#include <vector>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <chrono>

#include <rclcpp/rclcpp.hpp>
#include <wujihandcpp/protocol/handler.hpp>

using namespace std::chrono_literals;

static constexpr int NUM_POINTS = 6;  // First 6 points

class FilterDemoNode : public rclcpp::Node {
public:
    FilterDemoNode()
        : Node("filter_demo_node")
        , handler_(0x0483, -1, nullptr, 64, 0)
    {
        // Declare parameters
        declare_parameter("collection_duration", 10.0);  // seconds
        declare_parameter("sample_rate", 100.0);         // Hz
        declare_parameter("output_dir", std::string(TACTILE_VIZ_LOG_DIR));
        declare_parameter("smoothing_alpha", 0.3);       // EMA smoothing factor
        declare_parameter("max_slope", 500.0);           // Max allowed slope (N/s)

        collection_duration_ = get_parameter("collection_duration").as_double();
        sample_rate_ = get_parameter("sample_rate").as_double();
        output_dir_ = get_parameter("output_dir").as_string();
        smoothing_alpha_ = get_parameter("smoothing_alpha").as_double();
        max_slope_ = get_parameter("max_slope").as_double();

        // Create output directory
        std::filesystem::create_directories(output_dir_);

        // Generate timestamped filename
        auto now_time = std::chrono::system_clock::now();
        auto now_time_t = std::chrono::system_clock::to_time_t(now_time);
        std::stringstream ss;
        ss << std::put_time(std::localtime(&now_time_t), "%Y%m%d_%H%M%S");
        timestamp_str_ = ss.str();

        // Initialize filter states for 6 points + resultant
        for (int i = 0; i < NUM_POINTS; ++i) {
            filtered_state_[i] = {0.0, 0.0, 0.0};
            prev_raw_[i] = {0.0, 0.0, 0.0};
        }
        resultant_filtered_ = {0.0, 0.0, 0.0};
        prev_resultant_ = {0.0, 0.0, 0.0};
        first_sample_ = true;

        RCLCPP_INFO(get_logger(), "=== Tactile Filter Demo ===");
        RCLCPP_INFO(get_logger(), "Collecting first %d points + resultant force", NUM_POINTS);
        RCLCPP_INFO(get_logger(), "Duration: %.1f s, Rate: %.1f Hz", collection_duration_, sample_rate_);
        RCLCPP_INFO(get_logger(), "Alpha: %.2f, Max slope: %.1f N/s", smoothing_alpha_, max_slope_);
        RCLCPP_INFO(get_logger(), "Waiting for tactile data...");

        // Create timer
        auto period = std::chrono::duration<double>(1.0 / sample_rate_);
        timer_ = create_wall_timer(
            std::chrono::duration_cast<std::chrono::nanoseconds>(period),
            std::bind(&FilterDemoNode::collect_sample, this));

        start_time_ = now();
    }

private:
    struct Vec3 {
        double x, y, z;
    };

    double magnitude(const Vec3& v) {
        return std::sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
    }

    double filter_by_slope(double current, double previous, double dt) {
        double slope = (current - previous) / dt;
        double max_change = max_slope_ * dt;
        if (std::abs(slope) > max_slope_) {
            return previous + (slope > 0 ? max_change : -max_change);
        }
        return current;
    }

    Vec3 apply_filter(const Vec3& raw, Vec3& prev, Vec3& state, double dt) {
        // Slope filter first
        Vec3 slope_filtered;
        slope_filtered.x = filter_by_slope(raw.x, prev.x, dt);
        slope_filtered.y = filter_by_slope(raw.y, prev.y, dt);
        slope_filtered.z = filter_by_slope(raw.z, prev.z, dt);

        // Then EMA
        Vec3 result;
        result.x = smoothing_alpha_ * slope_filtered.x + (1.0 - smoothing_alpha_) * state.x;
        result.y = smoothing_alpha_ * slope_filtered.y + (1.0 - smoothing_alpha_) * state.y;
        result.z = smoothing_alpha_ * slope_filtered.z + (1.0 - smoothing_alpha_) * state.z;

        prev = raw;
        state = result;
        return result;
    }

    void collect_sample() {
        wujihandcpp::protocol::TactileData data;
        if (!handler_.get_tactile_data(data)) {
            return;
        }

        if (!collecting_) {
            collecting_ = true;
            start_time_ = now();
            RCLCPP_INFO(get_logger(), "Data received, starting collection...");
        }

        double elapsed = (now() - start_time_).seconds();
        double dt = 1.0 / sample_rate_;

        Sample sample;
        sample.time = elapsed;

        // Process first 6 points
        for (int i = 0; i < NUM_POINTS; ++i) {
            Vec3 raw = {data.points[i].x, data.points[i].y, data.points[i].z};
            sample.raw[i] = raw;
            sample.raw_mag[i] = magnitude(raw);

            if (first_sample_) {
                filtered_state_[i] = raw;
                prev_raw_[i] = raw;
                sample.filtered[i] = raw;
            } else {
                sample.filtered[i] = apply_filter(raw, prev_raw_[i], filtered_state_[i], dt);
            }
            sample.filtered_mag[i] = magnitude(sample.filtered[i]);
        }

        // Process resultant force
        Vec3 raw_res = {data.resultant_force.x, data.resultant_force.y, data.resultant_force.z};
        sample.raw_resultant = raw_res;
        sample.raw_resultant_mag = magnitude(raw_res);

        if (first_sample_) {
            resultant_filtered_ = raw_res;
            prev_resultant_ = raw_res;
            sample.filtered_resultant = raw_res;
            first_sample_ = false;
        } else {
            sample.filtered_resultant = apply_filter(raw_res, prev_resultant_, resultant_filtered_, dt);
        }
        sample.filtered_resultant_mag = magnitude(sample.filtered_resultant);

        samples_.push_back(sample);
        sample_count_++;

        // Progress
        if (static_cast<int>(elapsed) > last_progress_sec_) {
            last_progress_sec_ = static_cast<int>(elapsed);
            RCLCPP_INFO(get_logger(), "Collecting... %d/%d s", last_progress_sec_, static_cast<int>(collection_duration_));
        }

        if (elapsed >= collection_duration_) {
            timer_->cancel();
            export_data();
            rclcpp::shutdown();
        }
    }

    void export_data() {
        std::string output_file = output_dir_ + "/filter_demo_" + timestamp_str_ + ".csv";
        std::ofstream file(output_file);
        if (!file.is_open()) {
            RCLCPP_ERROR(get_logger(), "Failed to open: %s", output_file.c_str());
            return;
        }

        // Header
        file << "time";
        for (int i = 0; i < NUM_POINTS; ++i) {
            file << ",p" << i << "_raw_mag,p" << i << "_filtered_mag";
        }
        file << ",resultant_raw_mag,resultant_filtered_mag\n";

        // Data
        for (const auto& s : samples_) {
            file << std::fixed << std::setprecision(4) << s.time;
            for (int i = 0; i < NUM_POINTS; ++i) {
                file << "," << s.raw_mag[i] << "," << s.filtered_mag[i];
            }
            file << "," << s.raw_resultant_mag << "," << s.filtered_resultant_mag << "\n";
        }

        file.close();
        RCLCPP_INFO(get_logger(), "=== Done === %zu samples", sample_count_);
        RCLCPP_INFO(get_logger(), "Output: %s", output_file.c_str());
        RCLCPP_INFO(get_logger(), "Plot: python3 scripts/plot_filter_effect.py %s", output_file.c_str());
    }

    wujihandcpp::protocol::Handler handler_;
    rclcpp::TimerBase::SharedPtr timer_;

    double collection_duration_;
    double sample_rate_;
    std::string output_dir_;
    std::string timestamp_str_;
    double smoothing_alpha_;
    double max_slope_;

    bool collecting_ = false;
    size_t sample_count_ = 0;
    rclcpp::Time start_time_;
    int last_progress_sec_ = 0;
    bool first_sample_;

    // Filter states for 6 points
    std::array<Vec3, NUM_POINTS> filtered_state_;
    std::array<Vec3, NUM_POINTS> prev_raw_;
    Vec3 resultant_filtered_;
    Vec3 prev_resultant_;

    struct Sample {
        double time;
        std::array<Vec3, NUM_POINTS> raw;
        std::array<double, NUM_POINTS> raw_mag;
        std::array<Vec3, NUM_POINTS> filtered;
        std::array<double, NUM_POINTS> filtered_mag;
        Vec3 raw_resultant;
        double raw_resultant_mag;
        Vec3 filtered_resultant;
        double filtered_resultant_mag;
    };
    std::vector<Sample> samples_;
};

int main(int argc, char* argv[]) {
    rclcpp::init(argc, argv);
    try {
        rclcpp::spin(std::make_shared<FilterDemoNode>());
    } catch (const std::exception& e) {
        RCLCPP_ERROR(rclcpp::get_logger("filter_demo"), "Error: %s", e.what());
        return 1;
    }
    rclcpp::shutdown();
    return 0;
}
