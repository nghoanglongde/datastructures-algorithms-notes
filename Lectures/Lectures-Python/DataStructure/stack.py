#Sử dụng list trong python
#ngoài ra ta có thể sử dụng 2 thư viện đó là  collections.deque và queue.LifoQueue. Phần này các bạn tự tìm hiểu libary của nó
#from collections import deque  đây là thư viện collections với deque
#from queue import LifoQueue đây là thư viện queue


class Stack(list):
    def __init__(self):
        self.stack = []

    def push(self, data):
        self.stack += [data]

    def pop(self):
        self.stack.pop()

    def top(self):
        len_stack = len(self.stack)
        return self.stack[len_stack - 1]


def main():
    my_stack = Stack()  # khởi tạo stack

    #method push
    my_stack.push(5)
    my_stack.push(3)

    #method top
    print(my_stack.top())

    #method pop
    my_stack.pop()
    print(my_stack.top())

    #Các method khác như len sẽ được kế thừa từ class list


main()
