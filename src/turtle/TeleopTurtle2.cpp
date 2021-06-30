#include <chrono>
//#include <algorithm>
#include <functional>
#include "TeleopTurtle.h"
//#include <iostream>

using namespace std::chrono_literals;

void TeleopTurtle::initMsg()
{
    this->msg_.linear.x = 0.0;
    this->msg_.linear.y = 0.0;
    this->msg_.linear.z = 0.0;

    this->msg_.angular.x = 0.0;
    this->msg_.angular.y = 0.0;
    this->msg_.angular.z = 0.0;
}


void TeleopTurtle::forward()
{
    this->initMsg();
    this->msg_.linear.x = 2.0;

    RCLCPP_INFO(this->get_logger(), "forward");
    this->publisher_->publish(msg_);
}

void TeleopTurtle::backward()
{
    this->initMsg();
    this->msg_.linear.x = -2.0;

    RCLCPP_INFO(this->get_logger(), "backward");
    this->publisher_->publish(msg_);
}

void TeleopTurtle::rotateLeft()
{
    this->initMsg();
    this->msg_.angular.z = 2.0;

    RCLCPP_INFO(this->get_logger(), "left rotate");
    this->publisher_->publish(msg_);
}

void TeleopTurtle::rotateRight()
{
    this->initMsg();
    this->msg_.angular.z = -2.0;

    RCLCPP_INFO(this->get_logger(), "right rotate");
    this->publisher_->publish(msg_);
}


TeleopTurtle::TeleopTurtle()
    : Node("teleop_pub")
{
    this->publisher_ = this->Node::create_publisher<geometry_msgs::msg::Twist>("/turtle1/cmd_vel", 10);
    this->timer_ = this->create_wall_timer
        (2000ms, std::bind(&TeleopTurtle::timer_callback, this));

    this->timer_->cancel();
}


void TeleopTurtle::timer_callback()
{
    //geometry_msgs::msg::Twist msg = {{2.0, 0.0, 0.0}, {0.0, 0.0, 1.8}};
    
    

    geometry_msgs::msg::Twist msg;

    // char inp;
    // std::cout << "입력(i,j,k,l): ";
    // std::cin >> inp;

    // switch (inp){
    // case 'i': msg.linear.x = 2.0; break;
    // case 'k': msg.linear.x = -2.0; break;
    // case 'j': msg.angular.z = 0.785398; break;
    // case 'l': msg.angular.z = -0.785398; break;
    // }

    msg.linear.x = 2.0;
    msg.linear.y = 0.0;
    msg.linear.z = 0.0;

    msg.angular.x = 0.0;
    msg.angular.y = 0.0;
    msg.angular.z = 1.8;

    // RCLCPP_INFO(this->get_logger(), "twist msg publishing");
    // 콘솔창에 출력

    // this->publisher_->publish(msg);
}
