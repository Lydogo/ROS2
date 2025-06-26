#include "rclcpp/rclcpp.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include <chrono> // 引入时间相关头文件

using namespace std::chrono_literals;

class CircleMotion : public rclcpp::Node
{
public:
  explicit CircleMotion(const std::string& node_name) : Node(node_name)

  {
    publisher_ = this->create_publisher<geometry_msgs::msg::Twist>("/cmd_vel", 10);
    timer_ = this->create_wall_timer(500ms, std::bind(&CircleMotion::timer_callback, this));
  
  }

private:
  void timer_callback()
  {
    auto twist_msg = geometry_msgs::msg::Twist();
    twist_msg.linear.x = 2;
    twist_msg.angular.z = 8;
    
    publisher_->publish(twist_msg);
    RCLCPP_INFO(this->get_logger(), 
                "Publishing CircleMotion: linear.x=%.2f, angular.z=%.2f",
                twist_msg.linear.x, twist_msg.angular.z);
  }

  rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  auto node = std::make_shared<CircleMotion>("circle_motion");
  rclcpp::spin(node);
  rclcpp::shutdown();
  return 0;
}