#include <chrono>
#include <functional>
#include "teleopPub.h"

using namespace std::chrono_literals;

void teleopPub::initMsg()
{
    this->msg_.linear.x = 0.0;
    this->msg_.linear.y = 0.0;
    this->msg_.linear.z = 0.0;

    this->msg_.angular.x = 0.0;
    this->msg_.angular.y = 0.0;
    this->msg_.angular.z = 0.0;
}


void teleopPub::forward()
{
    this->initMsg();
    this->msg_.linear.x = 2.0;

    RCLCPP_INFO(this->get_logger(), "forward");
    this->publisher_->publish(msg_);
}

void teleopPub::backward()
{
    this->initMsg();
    this->msg_.linear.x = -2.0;

    RCLCPP_INFO(this->get_logger(), "backward");
    this->publisher_->publish(msg_);
}

void teleopPub::rotateLeft()
{
    this->initMsg();
    this->msg_.angular.z = 2.0;

    RCLCPP_INFO(this->get_logger(), "left rotate");
    this->publisher_->publish(msg_);
}

void teleopPub::rotateRight()
{
    this->initMsg();
    this->msg_.angular.z = -2.0;

    RCLCPP_INFO(this->get_logger(), "right rotate");
    this->publisher_->publish(msg_);
}

void teleopPub::stop()
{
    this->initMsg();

    RCLCPP_INFO(this->get_logger(), "stop");
    this->publisher_->publish(msg_);
}

teleopPub::teleopPub()
    : Node("teleop_pub")
{
    this->publisher_ = this->Node::create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 10);
    this->timer_ = this->create_wall_timer
        (2000ms, std::bind(&teleopPub::timer_callback, this));

    this->timer_->cancel();
}


void teleopPub::timer_callback()
{
    geometry_msgs::msg::Twist msg;

    msg_.linear.x = 2.0;
    msg_.linear.y = 0.0;
    msg_.linear.z = 0.0;

    msg_.angular.x = 0.0;
    msg_.angular.y = 0.0;
    msg_.angular.z = 1.8;

}