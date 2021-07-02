#include <memory>
#include <chrono>
#include <rclcpp/rclcpp.hpp>
#include <example_interfaces/srv/add_two_ints.hpp>

#include <cstdlib>

using namespace std::chrono_literals;


int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

//   if (argc != 3) {
//       RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "usage: add_two_ints_client X Y");
//       return 1;
//   }

  std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("client_node");
  
  // std::shared_ptr<rclcpp::Client<example_interfaces::srv::AddTwoInts> > client
  // rclcpp::Client<example_interfaces::srv::AddTwoInts>::SharedPtr client
  auto client
    = node->create_client<example_interfaces::srv::AddTwoInts>("add_two_ints");

  auto request = std::make_shared<example_interfaces::srv::AddTwoInts::Request>();

  request->a = 1;
  request->b = 2;
  // request->a = atoll(argv[1]);
  // request->b = atoll(argv[2]);


  while (!client->wait_for_service(1s)) {
    if (!rclcpp::ok()) {
      RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted while waiting for the service. Exiting.");
      return 0;
    }
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "service not available, waiting...");
  }

  auto result = client->async_send_request(request);

  // Wait for the result. 제대로 받아졌는지..
  if (rclcpp::spin_until_future_complete(node, result) ==
    rclcpp::executor::FutureReturnCode::SUCCESS)
  {
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "result(sum) : %ld", result.get()->sum);
  } 
  else
  {
    RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Failed to call service add_two_ints");
  }

  rclcpp::shutdown();

  return 0;
}
