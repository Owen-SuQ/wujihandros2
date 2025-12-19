/**
 * @file tactile_viz_node.cpp
 * @brief ROS2 node for 3D visualization of tactile sensor data
 *
 * This node reads tactile data from wujihandcpp and publishes MarkerArray
 * for visualization in RViz. Each tactile point is displayed as:
 * - A sphere at the point position
 * - An arrow showing the force vector direction and magnitude
 */

#include <cmath>
#include <array>
#include <memory>

#include <rclcpp/rclcpp.hpp>
#include <visualization_msgs/msg/marker_array.hpp>
#include <geometry_msgs/msg/transform_stamped.hpp>
#include <tf2_ros/static_transform_broadcaster.h>

#include <wujihandcpp/protocol/handler.hpp>

using namespace std::chrono_literals;
using visualization_msgs::msg::Marker;
using visualization_msgs::msg::MarkerArray;

class TactileVizNode : public rclcpp::Node {
public:
    TactileVizNode()
        : Node("tactile_viz_node")
        , handler_(0x0483, -1, nullptr, 64, 0)  // Connect to any wujihand device
    {
        // Declare parameters
        declare_parameter("frame_id", "tactile_frame");
        declare_parameter("publish_rate", 10.0);
        declare_parameter("grid.origin.x", 0.0);
        declare_parameter("grid.origin.y", 0.0);
        declare_parameter("grid.origin.z", 0.0);
        declare_parameter("grid.spacing", 0.005);  // 5mm spacing
        declare_parameter("grid.rows", 6);
        declare_parameter("grid.cols", 6);
        declare_parameter("arrow_scale", 0.001);   // Scale factor for force to arrow length
        declare_parameter("sphere_radius", 0.002); // 2mm sphere radius

        // Get parameters
        frame_id_ = get_parameter("frame_id").as_string();
        double publish_rate = get_parameter("publish_rate").as_double();
        double origin_x = get_parameter("grid.origin.x").as_double();
        double origin_y = get_parameter("grid.origin.y").as_double();
        double origin_z = get_parameter("grid.origin.z").as_double();
        double spacing = get_parameter("grid.spacing").as_double();
        int rows = get_parameter("grid.rows").as_int();
        int cols = get_parameter("grid.cols").as_int();
        arrow_scale_ = get_parameter("arrow_scale").as_double();
        sphere_radius_ = get_parameter("sphere_radius").as_double();

        // Initialize 6x6 grid positions
        initialize_grid_positions(origin_x, origin_y, origin_z, spacing, rows, cols);

        // Create publisher
        marker_pub_ = create_publisher<MarkerArray>("/tactile_markers", 10);

        // Create static transform broadcaster for tactile frame
        tf_broadcaster_ = std::make_shared<tf2_ros::StaticTransformBroadcaster>(this);
        publish_static_transform();

        // Create timer
        auto period = std::chrono::duration<double>(1.0 / publish_rate);
        timer_ = create_wall_timer(
            std::chrono::duration_cast<std::chrono::nanoseconds>(period),
            std::bind(&TactileVizNode::timer_callback, this));

        RCLCPP_INFO(get_logger(), "Tactile visualization node started");
        RCLCPP_INFO(get_logger(), "  Frame ID: %s", frame_id_.c_str());
        RCLCPP_INFO(get_logger(), "  Publish rate: %.1f Hz", publish_rate);
        RCLCPP_INFO(get_logger(), "  Grid: %dx%d, spacing: %.3f m", rows, cols, spacing);
    }

private:
    void initialize_grid_positions(double origin_x, double origin_y, double origin_z,
                                    double spacing, int rows, int cols) {
        // Create 6x6 grid of point positions
        // Points are arranged in row-major order
        for (int row = 0; row < rows && row < 6; ++row) {
            for (int col = 0; col < cols && col < 6; ++col) {
                int idx = row * cols + col;
                if (idx < 36) {
                    point_positions_[idx].x = origin_x + col * spacing;
                    point_positions_[idx].y = origin_y + row * spacing;
                    point_positions_[idx].z = origin_z;
                }
            }
        }
    }

    void publish_static_transform() {
        geometry_msgs::msg::TransformStamped transform;
        transform.header.stamp = now();
        transform.header.frame_id = "world";
        transform.child_frame_id = frame_id_;
        transform.transform.translation.x = 0.0;
        transform.transform.translation.y = 0.0;
        transform.transform.translation.z = 0.0;
        transform.transform.rotation.x = 0.0;
        transform.transform.rotation.y = 0.0;
        transform.transform.rotation.z = 0.0;
        transform.transform.rotation.w = 1.0;
        tf_broadcaster_->sendTransform(transform);
    }

    void timer_callback() {
        wujihandcpp::protocol::TactileData data;
        if (!handler_.get_tactile_data(data)) {
            // No data available yet
            return;
        }

        MarkerArray markers;
        auto stamp = now();

        // Create markers for each tactile point
        for (int i = 0; i < 36; ++i) {
            // Get force vector
            double fx = data.points[i].x;
            double fy = data.points[i].y;
            double fz = data.points[i].z;
            double force_magnitude = std::sqrt(fx*fx + fy*fy + fz*fz);

            // Sphere marker at point position
            Marker sphere;
            sphere.header.frame_id = frame_id_;
            sphere.header.stamp = stamp;
            sphere.ns = "tactile_points";
            sphere.id = i;
            sphere.type = Marker::SPHERE;
            sphere.action = Marker::ADD;
            sphere.pose.position.x = point_positions_[i].x;
            sphere.pose.position.y = point_positions_[i].y;
            sphere.pose.position.z = point_positions_[i].z;
            sphere.pose.orientation.w = 1.0;
            sphere.scale.x = sphere_radius_ * 2;
            sphere.scale.y = sphere_radius_ * 2;
            sphere.scale.z = sphere_radius_ * 2;

            // Color based on force magnitude (blue -> green -> red)
            double normalized_force = std::min(force_magnitude / 500.0, 1.0);
            sphere.color.r = static_cast<float>(normalized_force);
            sphere.color.g = static_cast<float>(1.0 - std::abs(normalized_force - 0.5) * 2);
            sphere.color.b = static_cast<float>(1.0 - normalized_force);
            sphere.color.a = 1.0f;

            markers.markers.push_back(sphere);

            // Arrow marker for force vector
            if (force_magnitude > 1.0) {  // Only show arrow if force > 1
                Marker arrow;
                arrow.header.frame_id = frame_id_;
                arrow.header.stamp = stamp;
                arrow.ns = "tactile_forces";
                arrow.id = i;
                arrow.type = Marker::ARROW;
                arrow.action = Marker::ADD;

                // Arrow defined by start and end points
                geometry_msgs::msg::Point start, end;
                start.x = point_positions_[i].x;
                start.y = point_positions_[i].y;
                start.z = point_positions_[i].z;

                // Scale force to arrow length
                double arrow_length = force_magnitude * arrow_scale_;
                double norm = force_magnitude;
                end.x = start.x + (fx / norm) * arrow_length;
                end.y = start.y + (fy / norm) * arrow_length;
                end.z = start.z + (fz / norm) * arrow_length;

                arrow.points.push_back(start);
                arrow.points.push_back(end);

                // Arrow shaft and head dimensions
                arrow.scale.x = 0.001;  // Shaft diameter
                arrow.scale.y = 0.002;  // Head diameter
                arrow.scale.z = 0.002;  // Head length (if 0, auto calculated)

                // Color: same as sphere
                arrow.color.r = sphere.color.r;
                arrow.color.g = sphere.color.g;
                arrow.color.b = sphere.color.b;
                arrow.color.a = 1.0f;

                markers.markers.push_back(arrow);
            }
        }

        // Add resultant force marker at center
        Marker resultant_arrow;
        resultant_arrow.header.frame_id = frame_id_;
        resultant_arrow.header.stamp = stamp;
        resultant_arrow.ns = "resultant_force";
        resultant_arrow.id = 0;
        resultant_arrow.type = Marker::ARROW;
        resultant_arrow.action = Marker::ADD;

        double rfx = data.resultant_force.x;
        double rfy = data.resultant_force.y;
        double rfz = data.resultant_force.z;
        double rf_magnitude = std::sqrt(rfx*rfx + rfy*rfy + rfz*rfz);

        if (rf_magnitude > 1.0) {
            geometry_msgs::msg::Point start, end;
            // Center of grid
            start.x = point_positions_[17].x;  // Approximately center
            start.y = point_positions_[17].y;
            start.z = point_positions_[17].z;

            double arrow_length = rf_magnitude * arrow_scale_ * 2;  // Larger for resultant
            end.x = start.x + (rfx / rf_magnitude) * arrow_length;
            end.y = start.y + (rfy / rf_magnitude) * arrow_length;
            end.z = start.z + (rfz / rf_magnitude) * arrow_length;

            resultant_arrow.points.push_back(start);
            resultant_arrow.points.push_back(end);

            resultant_arrow.scale.x = 0.002;  // Thicker shaft
            resultant_arrow.scale.y = 0.004;
            resultant_arrow.scale.z = 0.004;

            // Yellow for resultant force
            resultant_arrow.color.r = 1.0f;
            resultant_arrow.color.g = 1.0f;
            resultant_arrow.color.b = 0.0f;
            resultant_arrow.color.a = 1.0f;

            markers.markers.push_back(resultant_arrow);
        }

        marker_pub_->publish(markers);
    }

    // wujihandcpp handler
    wujihandcpp::protocol::Handler handler_;

    // ROS2 components
    rclcpp::Publisher<MarkerArray>::SharedPtr marker_pub_;
    rclcpp::TimerBase::SharedPtr timer_;
    std::shared_ptr<tf2_ros::StaticTransformBroadcaster> tf_broadcaster_;

    // Configuration
    std::string frame_id_;
    double arrow_scale_;
    double sphere_radius_;

    // 36 point positions (6x6 grid)
    struct Position { double x, y, z; };
    std::array<Position, 36> point_positions_;
};

int main(int argc, char* argv[]) {
    rclcpp::init(argc, argv);

    try {
        auto node = std::make_shared<TactileVizNode>();
        rclcpp::spin(node);
    } catch (const std::exception& e) {
        RCLCPP_ERROR(rclcpp::get_logger("tactile_viz"), "Error: %s", e.what());
        return 1;
    }

    rclcpp::shutdown();
    return 0;
}
