#ifndef TELEOPPUB_H
#define TELEOPPUB_H

#include <memory>
#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>

// extern const int DIRECTION_FORWARD;         // 전역변수를 다른 cpp에서 쓰려면 extern 선언이 필요
// extern const int DIRECTION_BACKWARD;
// extern const int ROTATE_LEFT;
// extern const int ROTATE_RIGHT;
// extern const int DIRECTION_STOP;


class TeleopPub : public rclcpp::Node {
public:
    TeleopPub();

    void move(int operation);
    // void forward();
    // void backward();
    // void rotateLeft();
    // void rotateRight();
    // void stop();

    static const int DIRECTION_FORWARD;   // 클래스에서 사용할 변수는 static멤버변수로 만들어 줌,,?
    static const int DIRECTION_BACKWARD;
    static const int ROTATE_LEFT;
    static const int ROTATE_RIGHT;
    static const int DIRECTION_STOP;

private:
    static const double MAX_SPEED;
    static const double MAX_RADIAN;

    static const double STEP_SPEED;
    static const double STEP_RADIAN;

    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
    geometry_msgs::msg::Twist msg_;

    void init_msg();
};

#endif
