#include "wujihand_driver/wujihand_driver_node.hpp"

int main(int argc, char* argv[])
{
  rclcpp::init(argc, argv);

  try {
    auto node = std::make_shared<wujihand_driver::WujiHandDriverNode>();
    rclcpp::spin(node);
  } catch (const std::exception& e) {
    RCLCPP_FATAL(rclcpp::get_logger("wujihand_driver"), "Exception: %s", e.what());
    rclcpp::shutdown();
    return 1;
  }

  rclcpp::shutdown();
  return 0;
}
