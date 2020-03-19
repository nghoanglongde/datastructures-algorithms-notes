#Cách 1: Sử dụng list trong python
class Stack(list):
    def __init__(self):
        self.stack = []
    def push(self, data):
        self.stack += [data]
    def pop(self):
        self.stack.pop()
    def top(self):
        print(self.stack[i])
def main():
    my_stack = Stack()
    my_stack.push(5)
    my_stack.push(3)
