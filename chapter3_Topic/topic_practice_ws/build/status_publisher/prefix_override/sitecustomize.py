import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/lyd/ROS2/chapter3_Topic/topic_practice_ws/install/status_publisher'
