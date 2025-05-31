cmake_minimum_required(VERSION 3.8)
project(demo_cpp_pkg)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

# 查找rclcpp头文件和库文件的路径
find_package(rclcpp REQUIRED) 

add_executable(cpp_node src/cpp_node.cpp)
add_executable(person_node src/class_node.cpp)


# # 给可执行文件包含头文件
# target_include_directories(cpp_node PUBLIC ${rclcpp_INCLUDE_DIRS})
# # 给可执行文件链接库文件
# target_link_libraries(cpp_node ${rclcpp_LIBRARIES})

ament_target_dependencies(cpp_node rclcpp)
ament_target_dependencies(person_node rclcpp)


install(TARGETS
  cpp_node  person_node
  DESTINATION lib/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
