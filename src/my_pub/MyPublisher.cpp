#include <chrono>
#include <algorithm>
#include <string>
#include "MyPublisher.h"

using namespace std::chrono_literals;


MyPublisher::MyPublisher()
    : Node("my_pub"), count_(0)
{
    this->publisher_ = this->Node::create_publisher<std_msgs::msg::String>("/my_topic", 10);
    this->timer_ = this->create_wall_timer(500ms, std::bind(&MyPublisher::timer_callback, this));

}

void MyPublisher::timer_callback()
{
    auto msg = std_msgs::msg::String();
    //std_msgs::msg::String msg;

    msg.data = "Hello, World!" + std::to_string(count_++);

    RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", msg.data.c_str());

    this->publisher_->publish(msg);

}