#ifndef TELEOPPUB_H
#define TELEOPPUB_H

#include <memory>
#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>


class TeleopPub : public rclcpp::Node {
public:
    TeleopPub();

    void forward();
    void backward();
    void rotateLeft();
    void rotateRight();
    void stop();

private:
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
    // rclcpp::TimerBase::SharedPtr timer_;

    geometry_msgs::msg::Twist msg_;

    void init_msg();

    // void timer_callback();
};

#endif
