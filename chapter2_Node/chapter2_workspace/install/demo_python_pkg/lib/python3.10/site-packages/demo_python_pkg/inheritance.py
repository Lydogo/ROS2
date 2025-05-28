from demo_python_pkg.class_node import PersonNode

class WriterNode(PersonNode):
    def __init__(self,book_value: str) ->None:
        print('WriterNode __init__方法被调用')
        self.book = book_value


def main():
    node = WriterNode('书名')
    node.eat('饭')