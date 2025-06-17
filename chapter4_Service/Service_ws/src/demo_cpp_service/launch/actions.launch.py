import launch
import launch.launch_description_sources
import launch_ros #launch需要的两个库
from ament_index_python.packages import get_package_share_directory

def generate_launch_description(): #名字固定，产生launch的描述
    action_declare_startup_rqt = launch.actions.DeclareLaunchArgument('startup_rqt',default_value="False")

    startup_rqt=launch.substitutions.LaunchConfiguration('startup_rqt', default="False")


#动作1：启动其他launch
    mutisim_launch_path = [get_package_share_directory('turtlesim'),'/launch','/multisim.launch.py']
    action_include_launch = launch.actions.IncludeLaunchDescription(
        launch.launch_description_sources.PythonLaunchDescriptionSource(
            mutisim_launch_path
        )
    )
#动作2：打印数据
    action_log_info = launch.actions.LogInfo(msg=str(mutisim_launch_path))

#动作3：执行进程，执行命令行
    action_topic_list = launch.actions.ExecuteProcess(
        condition = launch.conditions.IfCondition(startup_rqt), #通过条件控制
        cmd=['rqt']
    )

#动作4 组织动作成组
    action_group = launch.actions.GroupAction(
        [
            #定时器
            launch.actions.TimerAction(period=2.0,actions=[action_include_launch]),
            launch.actions.TimerAction(period=4.0,actions=[action_topic_list])
        ]
    )

    return launch.LaunchDescription([
        action_log_info,
        action_group

    ]) #返回值也固定，执行动作
