#include <memory>
#include <rclcpp/rclcpp.hpp>
#include <turtlebot3_msgs/srv/sound.hpp>
#include "SoundSrv.h"


int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    
    std::shared_ptr<SoundSrv> soundSrv = std::make_shared<SoundSrv>();


    soundSrv->makeRequest(3);


    while(!soundSrv->waitServer()) {
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "waiting service");
    }

    if (soundSrv->sendRequest()) {
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "success");
    } else {
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "fail");
    }


    rclcpp::shutdown();

    return 0;
}
