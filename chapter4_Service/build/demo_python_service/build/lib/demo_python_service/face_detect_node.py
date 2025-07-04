import rclpy
from rclpy.node import Node
from chapt4_interfaces.srv import FaceDetector #导入消息接口
from ament_index_python.packages import get_package_share_directory
from cv_bridge import CvBridge # 用于图像转换格式
import cv2
import face_recognition
import time
from rcl_interfaces.msg import SetParametersResult #参数设置的消息接口

class FaceDetectNode(Node):
    def __init__(self):
        super().__init__('face_detect_node')
        self.bridge = CvBridge()
        self.service = self.create_service(FaceDetector, '/face_detect', self.detect_face_callback) #创建服务
        self.defaut_image_path = get_package_share_directory('demo_python_service')+'/resource/default.jpg'
        self.upsample_times = 1
        self.model = "hog"
        # 声明和获取参数
        self.declare_parameter('face_locations_upsample_times', 1)
        self.declare_parameter('face_locations_model', "hog")
        self.model = self.get_parameter("face_locations_model").value
        self.upsample_times = self.get_parameter("face_locations_upsample_times").value
        self.set_parameters([rclpy.Parameter('face_locations_model', rclpy.Parameter.Type.STRING, 'cnn')])
        self.add_on_set_parameters_callback(self.parameter_callback)

        self.get_logger().info('人脸检测服务开始！')

    def parameter_callback(self, parameters): #订阅参数更新
        for parameter in parameters:
            self.get_logger().info(
                f'参数 {parameter.name} 设置为：{parameter.value}')
            if parameter.name == 'face_locations_upsample_times':
                self.upsample_times = parameter.value
            if parameter.name == 'face_locations_model':
                self.mode = parameter.value
        return SetParametersResult(successful=True) 
    

    def detect_face_callback(self, request, response):
        if request.image.data: #判断图像是否为空
            cv_image = self.bridge.imgmsg_to_cv2(
                request.image)
        else:
            cv_image = cv2.imread(self.defaut_image_path)
            self.get_logger().info('传入图像为空，使用默认图像')

        start_time = time.time()
        self.get_logger().info('加载完图像，开始检测')
        face_locations = face_recognition.face_locations(cv_image, number_of_times_to_upsample=self.upsample_times, model=self.model)
        end_time = time.time()
        self.get_logger().info(f'检测完成，耗时{end_time-start_time}')
        response.number = len(face_locations)
        response.use_time = end_time - start_time
        for top, right, bottom, left in face_locations: #遍历，并加到response的对应属性中
            response.top.append(top)
            response.right.append(right)
            response.bottom.append(bottom)
            response.left.append(left)
        return response #必须返回response


def main(args=None):
    rclpy.init(args=args)
    node = FaceDetectNode()
    rclpy.spin(node)
    rclpy.shutdown()
