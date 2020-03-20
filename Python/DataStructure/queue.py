#Sử dụng list trong python
#ngoài ra ta có thể sử dụng 2 thư viện đó là queue.LifoQueue. Phần này các bạn tự tìm hiểu libary của nó
#from queue import LifoQueue đây là thư viện queue


class Queue(list):
    def __init__(self):
        self.queue = []

    def push(self, data):
        self.queue += [data]

    def pop(self):
        self.queue.pop(0)

    def front(self):
        return self.queue[0]


def main():
    my_queue = Queue()  # khởi tạo stack

    #method push
    my_queue.push(1)
    my_queue.push(3)
    my_queue.push(9)
    my_queue.push(2)

    #method top
    print(my_queue.front())

    #method pop
    my_queue.pop()
    print(my_queue.front())

    #Các method khác như len sẽ được kế thừa từ class list


main()
