#include <memory>
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>


class MySubscriber : public rclcpp::Node {
public:
    MySubscriber();

private:
    void msg_callback(const std_msgs::msg::String::SharedPtr msg) const;  // 특정 이벤트가 발생했을때 지정하는 함수 > 콜백, 이벤트핸들러

    rclcpp::Subscription<std_msgs::msg::String>::SharedPtr subscription_;

};