import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/lyd/ROS2/chapter8_Navigation2/chapt8_ws/install/autopatrol_robot'
