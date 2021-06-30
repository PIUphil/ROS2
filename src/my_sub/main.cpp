#include "MySubscriber.h"

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MySubscriber>());     // 쉐어드포인트 넘겨줌??
    rclcpp::shutdown();

    return 0;
}