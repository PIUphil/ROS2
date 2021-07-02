#include <memory>         // sharedPtr를 쓰기위해
#include <rclcpp/rclcpp.hpp>
#include <example_interfaces/srv/add_two_ints.hpp>


// request --> response
void add(const std::shared_ptr<example_interfaces::srv::AddTwoInts::Request> request,
               std::shared_ptr<example_interfaces::srv::AddTwoInts::Response> response)
{
  response->sum = request->a + request->b;

  // RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "sending back response");
  // RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Incoming request \na: %ld" " b: %ld", request->a, request->b);
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "sending back response: [%ld]", (long int)response->sum);
}


int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("service_node");

  rclcpp::Service<example_interfaces::srv::AddTwoInts>::SharedPtr service = node->create_service<example_interfaces::srv::AddTwoInts>("add_two_ints", &add);

  RCLCPP_INFO(node->get_logger(), "Ready to service.");
  //RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Ready to service.");

  rclcpp::spin(node);

  rclcpp::shutdown();

  return 0;
}