#ifndef TeleopTurtle_H
#define TeleopTurtle_H

#include <memory>
#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>


class TeleopTurtle : public rclcpp::Node {
public:
    TeleopTurtle();

    void forward();
    void backward();
    void rotateLeft();
    void rotateRight();

private:
    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;

    geometry_msgs::msg::Twist msg_;

    void initMsg();

    void timer_callback();
};

#endif
