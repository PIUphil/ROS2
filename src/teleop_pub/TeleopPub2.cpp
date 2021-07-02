// #include <functional>
#include <algorithm>
#include "TeleopPub.h"

const int TeleopPub::DIRECTION_FORWARD = 1;
const int TeleopPub::DIRECTION_BACKWARD = 2;
const int TeleopPub::ROTATE_LEFT = 3;
const int TeleopPub::ROTATE_RIGHT = 4;
const int TeleopPub::DIRECTION_STOP = 5;

const double TeleopPub::MAX_SPEED = 0.22;       // 최대속도
const double TeleopPub::MAX_RADIAN = 2.84;      // 최대각도

const double TeleopPub::STEP_SPEED = 0.02;
const double TeleopPub::STEP_RADIAN = 0.1;

using std::min;
using std::max;

void TeleopPub::init_msg()
{
    this->msg_.linear.x = 0.0;
    this->msg_.linear.y = 0.0;
    this->msg_.linear.z = 0.0;

    this->msg_.angular.x = 0.0;
    this->msg_.angular.y = 0.0;
    this->msg_.angular.z = 0.0;
}

TeleopPub::TeleopPub()
    : Node("teleop_pub")
{
    this->publisher_ = this->Node::create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", 10);
    this->init_msg();
}

void TeleopPub::move(int operation)
{
    // this->init_msg();
    switch (operation) 
    {
        case DIRECTION_FORWARD:
            // this->msg_.linear.x += 0.02;
            // if (this->msg_.linear.x > TeleopPub::MAX_SPEED)
            //     this->msg_.linear.x = TeleopPub::MAX_SPEED;
            this->msg_.linear.x = min(TeleopPub::MAX_SPEED, this->msg_.linear.x + STEP_SPEED);
            RCLCPP_INFO(this->get_logger(), "forward");
            break;
        case DIRECTION_BACKWARD:
            // this->msg_.linear.x += -0.02;
            // if (this->msg_.linear.x <= -TeleopPub::MAX_SPEED)
            //     this->msg_.linear.x = -TeleopPub::MAX_SPEED;
            this->msg_.linear.x = max(-TeleopPub::MAX_SPEED, this->msg_.linear.x - STEP_SPEED);
            RCLCPP_INFO(this->get_logger(), "backward");
            break;
        case ROTATE_LEFT:
            // this->msg_.angular.z += 0.1;
            // if (this->msg_.angular.z > TeleopPub::MAX_RADIAN)
            //     this->msg_.angular.z = TeleopPub::MAX_RADIAN;
            this->msg_.angular.z = min(TeleopPub::MAX_RADIAN, this->msg_.angular.z + STEP_RADIAN);
            RCLCPP_INFO(this->get_logger(), "rotate_left");
            break;
        case ROTATE_RIGHT:  
            // this->msg_.angular.z += -0.1;
            // if (this->msg_.angular.z < -TeleopPub::MAX_RADIAN)
            //     this->msg_.angular.z = -TeleopPub::MAX_RADIAN;
            this->msg_.angular.z = max(-TeleopPub::MAX_RADIAN, this->msg_.angular.z - STEP_RADIAN);
            RCLCPP_INFO(this->get_logger(), "rotate_right");
            break;
        case DIRECTION_STOP:
            this->init_msg();
            RCLCPP_INFO(this->get_logger(), "stop");
            break;
    }
    this->publisher_->publish(msg_);
}

// void TeleopPub::forward()
// {
//     this->init_msg();
//     this->msg_.linear.x = 0.2;
    
//     RCLCPP_INFO(this->get_logger(), "forward");
//     this->publisher_->publish(msg_);
// }

// void TeleopPub::backward()
// {
//     this->init_msg();
//     this->msg_.linear.x = -0.2;

//     RCLCPP_INFO(this->get_logger(), "backward");
//     this->publisher_->publish(msg_);
// }

// void TeleopPub::rotateLeft()
// {
//     this->init_msg();
//     this->msg_.angular.z = 2.0;

//     RCLCPP_INFO(this->get_logger(), "left rotate");
//     this->publisher_->publish(msg_);
// }

// void TeleopPub::rotateRight()
// {
//     this->init_msg();
//     this->msg_.angular.z = -2.0;

//     RCLCPP_INFO(this->get_logger(), "right rotate");
//     this->publisher_->publish(msg_);
// }

// void TeleopPub::stop()
// {
//     this->init_msg();

//     RCLCPP_INFO(this->get_logger(), "stop");
//     this->publisher_->publish(msg_);
// }
