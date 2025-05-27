#include "rclcpp/rclcpp.hpp"
#include <iostream>
using namespace std;

int main(int argc, char **argv) //二维数组
{
    
    rclcpp::init(argc, argv);
    auto node = std::make_shared<rclcpp::Node>("cpp_node");
    RCLCPP_INFO(node->get_logger(), "Cpp 节点");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}