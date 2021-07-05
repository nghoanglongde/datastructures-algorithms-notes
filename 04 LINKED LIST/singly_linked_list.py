# Singly-linked list implementation
class Node:
    def __init__(self, value):
        self.val = value
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None
        self.tail = None
        self.size = 0

    def addAtTail(self, value):
        new_node = Node(value)
        self.size += 1
        if self.head is None:
            self.head = new_node
            self.tail = self.head
        else:
            self.tail.next = new_node
            self.tail = new_node

    def addAtHead(self, value):
        new_node = Node(value)
        self.size += 1
        if self.head is None:
            self.head = new_node
            self.tail = self.head
        else:
            new_node.next = self.head
            self.head = new_node

    def addAtIndex(self, index, value):
        if index < 0 or index > (self.size - 1):
            print(f"Not support delete at index: {index}")
        else:
            new_node = Node(value)
            if index == 0:
                self.addAtHead(value)
            elif index == (self.size - 1):
                self.addAtTail(value)
            else:
                cur = self.head
                for i in range(0, index - 1):
                    cur = cur.next
                new_node.next = cur.next
                cur.next = new_node

    def deleteAtHead(self):
        if self.head.next is None:
            self.head = None
        else:
            self.head = self.head.next

    def deleteAtTail(self):
        cur = self.head
        while cur.next.next is not None:
            cur = cur.next
        cur.next = None

    def deleteAtIndex(self, index):
        if index < 0 or index > (self.size - 1):
            print(f"Not support delete at index: {index}")
        else:
            if index == 0:
                self.deleteAtHead()
            elif index == (self.size - 1):
                self.deleteAtTail()
            else:
                cur = self.head
                for i in range(0, index - 1):
                    cur = cur.next
                cur.next = cur.next.next
    
    def output_linked_list(self):
        cur_node = self.head
        while cur_node is not None:
            print(cur_node.val)
            cur_node = cur_node.next





if __name__ == '__main__':
    my_linkedlist = LinkedList()
    my_linkedlist.addAtTail(5)
    my_linkedlist.addAtTail(2)
    my_linkedlist.addAtTail(6)
    my_linkedlist.addAtTail(1)
    my_linkedlist.addAtHead(4)

    my_linkedlist.output_linked_list()