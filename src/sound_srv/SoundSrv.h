#ifndef SOUND_SRV_H
#define SOUND_SRV_H

#include <memory>
#include <rclcpp/rclcpp.hpp>
#include <turtlebot3_msgs/srv/sound.hpp>


class SoundSrv : public rclcpp::Node {
public:
    SoundSrv();
    void makeRequest(int value);
    bool waitServer() const;
    bool sendRequest() const;

    static const int SOUND_POWER_OFF;
    static const int SOUND_POWER_ON;
    static const int SOUND_LOW_BATTERY;
    static const int SOUND_ERROR;

private:
    std::shared_ptr<rclcpp::Client<turtlebot3_msgs::srv::Sound> > client;
    //rclcpp::Client<turtlebot3_msgs::srv::Sound>::SharedPtr client;

    std::shared_ptr<turtlebot3_msgs::srv::Sound::Request> request; 

};

#endif
