#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/float32.hpp"
#include <chrono>
using namespace std::chrono_literals;

class BatteryPublisher : public rclcpp::Node
{
public:
    BatteryPublisher() : Node("battery_publisher"), battery_level_(100.0)
    {
        publisher_ = this->create_publisher<std_msgs::msg::Float32>("battery_level", 10);
        timer_ = this->create_wall_timer(
            1000ms, std::bind(&BatteryPublisher::publish_battery_level, this));
    }

private:
    void publish_battery_level()
    {
        auto message = std_msgs::msg::Float32();
        message.data = battery_level_;
        RCLCPP_INFO(this->get_logger(), "Publishing: '%f'", message.data);
        publisher_->publish(message);
        battery_level_ -= 0.5;
        if (battery_level_ < 0.0)
        {
            battery_level_ = 100.0;
        }
    }

    rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    float battery_level_;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<BatteryPublisher>());
    rclcpp::shutdown();
    return 0;
}
