from demo_python_pkg.class_node import PersonNode

class WriterNode(PersonNode):
    def __init__(self,name_value: str,age_value: int,book_value: str) ->None:
        print('WriterNode __init__方法被调用')
        super().__init__(name_value,age_value) #调用父类的__init__
        self.book = book_value


def main():
    node = WriterNode('AAA',18,'书名')
    node.eat('饭')