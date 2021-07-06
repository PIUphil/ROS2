#include "SoundSrv.h"
#include <chrono>

using namespace std::chrono_literals;

const int SoundSrv::SOUND_POWER_OFF = 0;
const int SoundSrv::SOUND_POWER_ON = 1;
const int SoundSrv::SOUND_LOW_BATTERY = 2;
const int SoundSrv::SOUND_ERROR = 3;


SoundSrv::SoundSrv() 
    : Node("sound_srv")
{   
    this-> client = this->Node::create_client<turtlebot3_msgs::srv::Sound>("/sound");
}

void SoundSrv::makeRequest(int value) 
{
    this->request = std::make_shared<turtlebot3_msgs::srv::Sound::Request>();
    request-> value = value;    // 0, 1, 2, 3
}

bool SoundSrv::waitServer() const
{
    return this-> client->wait_for_service(1s);

    // while(!this->client-> wait_for_service(1s)) {
    //     RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "waiting service");
    // }
}

bool SoundSrv::sendRequest() const 
{
    auto result = client->async_send_request(this->request);

    //std::shared_ptr<SoundSrv> node_ptr;
    //rclcpp::node_interfaces::NodeBaseInterface::SharedPtr node_ptr;

    return (rclcpp::spin_until_future_complete(rclcpp::Node::make_shared("sound_srv"), result) 
          ==rclcpp::executor::FutureReturnCode::SUCCESS);

    // if (rclcpp::spin_until_future_complete(node, result) 
    //     ==rclcpp::executor::FutureReturnCode::SUCCESS) {
    //     RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "success");
    // } else {
    //     RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "fail");
    // }
}
