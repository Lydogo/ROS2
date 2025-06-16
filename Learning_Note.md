# 四大通信机制

## 1）话题
## 2）服务
## 3）参数
## 4）动作

# 1.4.1 linux终端基础操作

## 文件：
cd ~  
#进入主目录

mkdir chapt1
#在主目录下创建chapt1文件夹

touch test_file
#如果文件不存在，则创建新的文件；如果文件存在，则修改文件的修改日期

ls
#列出目录的全部内容

pwd
#查看当前路径

cat
#concatenate，查看文件内容、创建文件、文件合并、追加文件内容等功能

nano
ubuntu自带终端文本编辑工具

chmod a+x 1.py 给一个普通文件增加可执行命令

## 帮助
rm --help
会出现指令相关用法

# 1.4.4 cpp文件编译指令
## g++
g++ cpp_test.cpp
直接编译cpp文件，对于简单文件可以使用，对于依赖太多的指令，较为麻烦

## cmake

1.touch CmakeLists.txt
2.输入以下指令
cmake_minimum_required(VERSION 3.8)
project(Project_Name)
add_executable(Cmake_exe_Name cpp_text.cpp)
3.make
4../Cmake_exe_Name

## 在linux中，以.开头的文件或文件夹是隐藏文件


# 2.2 在功能包中编写Python节点
## $ros2 pkg create --build-type ament_cmake --license Apache-2.0 demo_python_pkg
## $colcon build
## 添加环境变量：$source install/setup.bash
## 运行：$ros2 run name


# 2.3.1 在功能包中编写Cpp节点
## 会多一个CMakeLists.txt的文件
## $ldd cpp_node 查看某节点的依赖关系

# 2.4 工作空间
一个完整的机器人项目往往又多个不同的功能模块组成，所以需要对多个功能包进行组合
## 创建工作空间 $mkdir -p chapter_ws/src
## 工作空间可以单独构建 $colcon build --packages-select demo_cpp_pkg

# 2.5.2 C++新特性
## 自动类型推导
```C++
auto node=
std::make_shared<rclcpp::Npde>
("cpp_node")
```
node 是自动推导类型

## 智能指针
### 共享指针：用于解决占有内存却没有使用的问题 会记录使用某块内存的资源数量

## Lambda函数：换个语法写的函数
```C++
[capture list](parameters)->return_type
{function body}
```
## 自由函数
```C++
void save_with_free_fun(const std::string &file_name)
{
    std::cout<<"调用了自由函数，保存："<<file_name<<std::endl;
}
```
## 成员函数
```C++
class FileSave
{
public:
    void save_with_mumber_fun(const std::string &file_name)
    {
        std::cout<<"调用了成员函数，保存："<<file_name<<std::endl;
    }
}

```

## 函数包装器：统一上述3种函数的调用方式

# 2.5.3多线程与回调函数


# 3.1 话题

## 查看话题消息接口
$ros2 topic info /turtle1/cmd_vel

## 消息接口详细定义
$ros2 interface show geometry_msgs/msg/Twist

## 发布
$ros2 topic pub /turtle1/cmd_vel geometry_msgs/msg/Twist "{linear: {x: 0.5, y: 0.0} , angular: {z: 0.0}}"
pub:表示发布
/turtle1/cmd_vel：话题名字
geometry_msgs/msg/Twist：消息接口

# 4.1服务

在 ROS 2（Robot Operating System 2） 中，服务（Service） 是一种基于 请求-响应（Request-Response） 模型的通信机制，允许节点（Nodes）之间进行同步交互。服务由 服务端（Server） 和 客户端（Client） 组成：

## 服务端
服务端是 响应请求 的一方，它：监听 某个服务（Service）的请求。收到请求后，执行 回调函数 处理请求，并返回 响应（Response）。

## 客户端
客户端是 发起请求 的一方，它：向服务端 发送请求（Request） 并 等待响应（Response）。可以是 同步（阻塞） 或 异步（非阻塞） 调用。

## 参数设置
运行节点时单独设置参数
ros2 run demo_python_service face_detect_node --ros-args -p model:=cnn

请求端参数设置
ros2 param set /face_detect_node face_locations_upsample_times 2