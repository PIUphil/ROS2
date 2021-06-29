#include <memory>
#include "MyPublisher.h"

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MyPublisher>());
  rclcpp::shutdown();

  return 0;
}
