import rclpy
from rclpy.node import Node

def main():
    rclpy.init() #初始化工作，便于后续分配资源
    node = Node("python_node")  #创建节点的实例对象
    node.get_logger().info('Python节点')    #打印log
    node.get_logger().warn('Python节点')    #打印log
    rclpy.spin(node)    #运行节点，不打断不会主动退出
    rclpy.shutdown()
