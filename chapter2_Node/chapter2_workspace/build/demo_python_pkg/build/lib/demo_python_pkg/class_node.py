import rclpy
from rclpy.node import Node

class PersonNode(Node):
    def __init__(self,node_name: str,name_value: str,age_value: int) ->None:
        print('PersonNode __init__方法被调用')
        super().__init__(node_name)
        self.name = name_value
        self.age = age_value

    def eat(self,food_name: str):
        # print(f"{self.name},{self.age}eat {food_name}")
        self.get_logger().info(f"{self.name},{self.age}eat {food_name}")
def main():
    rclpy.init()
    node = PersonNode('ROS2bbb','AAA',18)
    node.eat('饭')
    rclpy.spin(node)
    rclpy.shutdown()