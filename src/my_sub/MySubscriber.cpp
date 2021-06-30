#include "MySubscriber.h"
#include <algorithm>

using std::placeholders::_1;
    
    
MySubscriber::MySubscriber() 
    : Node("my_sub")
{
    this->subscription_ = 
        this->Node::create_subscription<std_msgs::msg::String>
        ("/my_topic", 10, std::bind(&MySubscriber::msg_callback, this, _1));
    
}


void MySubscriber::msg_callback(const std_msgs::msg::String::SharedPtr msg) const   // 특정 이벤트가 발생했을때 지정하는 함수 > 콜백, 이벤트핸들러
{
    RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg->data.c_str());
}