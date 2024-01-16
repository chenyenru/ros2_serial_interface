from launch import LaunchDescription
from launch_ros.actions import Node
#if you run the launch file using ros2 launch after changing the parameter values, you need to rerun colcon build
def generate_launch_description():
    return LaunchDescription([
        Node(
            package='ros2_serial_interface',
            executable='serial_server',
            name='serial_server_node',
            output='screen',
            emulate_tty=True,
           parameters=[
			('device', '/dev/ttyACM0'), #device we are transmitting to & receiving messages from
		    ('wheel_instructions_topic', 'wheel_instructions_topic'),
		    ('move_straight_cmd', 'w'),
		    ('turn_right_cmd', 'd'),
		    ('turn_left_cmd', 'a')		
			]
        )
    ])