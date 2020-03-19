class Node:
    def __init__(self, data):
        self.data = data
        self.next_sibling = None


class SinglyLinkedList:
    def __init__(self):
        self.root = None

  # insertion method for the linked list
    def insert(self, data):
        newNode = Node(data)
        if(self.root):
            current = self.root
            while(current.next_sibling):
                current = current.next_sibling
            current.next_sibling = newNode
        else:
            self.root = newNode

    def outputLinked(self):
        current = self.root
        while(current):
            print(current.data, end=' ')
            current = current.next_sibling

#tương tự cho danh sách nối vòng 1 hướng, 2 hướng


def main():
    n = int(input())
    root = SinglyLinkedList()
    for i in range(n):
        data = int(input())
        root.insert(data)
    root.outputLinked()


main()
