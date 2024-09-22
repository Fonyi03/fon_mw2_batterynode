from launch import LaunchDescription
from launch_ros.actions import Node

def generate_launch_description():
    return LaunchDescription([
        Node(
            package='battery_manager',
            executable='battery_publisher',
            name='battery_publisher'
        ),
        Node(
            package='battery_manager',
            executable='battery_subscriber',
            name='battery_subscriber'
        )
    ])
