// #include <chrono>
#include <functional>
#include "TeleopPub.h"

// using namespace std::chrono_literals;

void TeleopPub::init_msg()
{
    this->msg_.linear.x = 0.0;
    this->msg_.linear.y = 0.0;
    this->msg_.linear.z = 0.0;

    this->msg_.angular.x = 0.0;
    this->msg_.angular.y = 0.0;
    this->msg_.angular.z = 0.0;
}


void TeleopPub::forward()
{
    this->init_msg();
    this->msg_.linear.x = 0.2;
    
    RCLCPP_INFO(this->get_logger(), "forward");
    this->publisher_->publish(msg_);
}

void TeleopPub::backward()
{
    this->init_msg();
    this->msg_.linear.x = -0.2;

    RCLCPP_INFO(this->get_logger(), "backward");
    this->publisher_->publish(msg_);
}

void TeleopPub::rotateLeft()
{
    this->init_msg();
    this->msg_.angular.z = 2.0;

    RCLCPP_INFO(this->get_logger(), "left rotate");
    this->publisher_->publish(msg_);
}

void TeleopPub::rotateRight()
{
    this->init_msg();
    this->msg_.angular.z = -2.0;

    RCLCPP_INFO(this->get_logger(), "right rotate");
    this->publisher_->publish(msg_);
}

void TeleopPub::stop()
{
    this->init_msg();

    RCLCPP_INFO(this->get_logger(), "stop");
    this->publisher_->publish(msg_);
}

TeleopPub::TeleopPub()
    : Node("teleop_pub")
{
    this->publisher_ = this->Node::create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", 10);
    /*this->timer_ = this->create_wall_timer
        (2000ms, std::bind(&TeleopPub::timer_callback, this));

    this->timer_->cancel();*/
}

/*
void TeleopPub::timer_callback()
{
    geometry_msgs::msg::Twist msg;

    msg_.linear.x = 2.0;
    msg_.linear.y = 0.0;
    msg_.linear.z = 0.0;

    msg_.angular.x = 0.0;
    msg_.angular.y = 0.0;
    msg_.angular.z = 1.8;

}*/
