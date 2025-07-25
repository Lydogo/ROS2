from setuptools import find_packages, setup

package_name = 'demo_python_pkg'

setup(
    name=package_name,
    version='0.0.0',
    packages=find_packages(exclude=['test']),
    data_files=[
        ('share/ament_index/resource_index/packages',
            ['resource/' + package_name]),
        ('share/' + package_name, ['package.xml']),
    ],
    install_requires=['setuptools'],
    zip_safe=True,
    maintainer='lyd',
    maintainer_email='leeydogo@gmail.com',
    description='TODO: Package description',
    license='Apache-2.0',
    tests_require=['pytest'],
    entry_points={
        'console_scripts': [
            'python_node = demo_python_pkg.python_node:main',#生成一个名为pytho_node的可执行文件，后面是路径
            'class_node = demo_python_pkg.class_node:main',
            'inheritance_node = demo_python_pkg.inheritance_node:main',
            'thread_test = demo_python_pkg.thread_test:main',

            
        ],
    },
)
