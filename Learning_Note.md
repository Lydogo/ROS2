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