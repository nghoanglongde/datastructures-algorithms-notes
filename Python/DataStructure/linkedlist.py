class Node:
    def __init__(self, data):
        self.data = data
        self.next_sibling = None

#Cách 1 dùng class
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

#cách 2 dùng functional programming
# def outputLinked(root):
#         current = root
#         while(current):
#             print(current.data, end=' ')
#             current = current.next_sibling

# def insert(root, data):
#     newNode = Node(data)
#     if(root == None):
#         root = newNode
#         return root
#     else:
#         current = root
#         while(current.next_sibling):
#             current = current.next_sibling
#         current.next_sibling = newNode
#         return root

def main():
    #Cách 1
    n = int(input())
    root = SinglyLinkedList()
    for i in range(n):
        data = int(input())
        root.insert(data)
    root.outputLinked()

    #Cách 2
    # n = int(input())
    # root = None
    # for i in range(n):
    #     data = int(input())
    #     root = insert(root, data)
    # outputLinked(root)

main()
