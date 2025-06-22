import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/lyd/ROS2/chapter5_Tools/chapt5_ws/install/demo_python_tf'
