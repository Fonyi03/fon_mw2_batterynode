#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32.hpp"

class BatterySubscriber : public rclcpp::Node
{
public:
    BatterySubscriber() : Node("battery_subscriber")
    {
        subscription_ = this->create_subscription<std_msgs::msg::Float32>(
            "battery_level", 10, std::bind(&BatterySubscriber::handle_battery_level, this, std::placeholders::_1));
    }

private:
    void handle_battery_level(const std_msgs::msg::Float32::SharedPtr msg)
    {
        RCLCPP_INFO(this->get_logger(), "Battery level: '%f'", msg->data);
    }

    rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr subscription_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<BatterySubscriber>());
    rclcpp::shutdown();
    return 0;
}
