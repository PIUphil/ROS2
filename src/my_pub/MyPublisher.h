#ifndef MY_PUBLISHER_H
#define MY_PUBLISHER_H
#include <memory>

#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>


class MyPublisher : public rclcpp::Node {
public:
    MyPublisher();

private:
    rclcpp::TimerBase::SharedPtr timer_;
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;

    int count_;

    void timer_callback();
};

#endif