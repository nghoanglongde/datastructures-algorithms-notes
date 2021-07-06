# Singly-linked list implementation
class Node:
    def __init__(self, value) -> None:
        self.val = value
        self.next = None

class SinglyLinkedList:
    def __init__(self) -> None:
        self.head = None
        self.tail = None
        self.size = 0

    def addAtTail(self, value) -> None:
        new_node = Node(value)
        if self.head is None:
            self.head = new_node
            self.tail = self.head
        else:
            self.tail.next = new_node
            self.tail = new_node
        self.size += 1

    def addAtHead(self, value) -> None:
        new_node = Node(value)
        if self.head is None:
            self.head = new_node
            self.tail = self.head
        else:
            new_node.next = self.head
            self.head = new_node
        self.size += 1

    def addAtIndex(self, index: int, value: int) -> None:
        if index < 0 or index > (self.size - 1):
            print(f"Not support insert at index: {index}")
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
            self.size += 1

    def deleteAtHead(self) -> None:
        if self.head.next is None:
            self.head = None
        else:
            self.head = self.head.next
        self.size -= 1

    def deleteAtTail(self) -> None:
        cur = self.head
        while cur.next.next is not None:
            cur = cur.next
        cur.next = None
        self.size -= 1

    def deleteAtIndex(self, index: int) -> None:
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
            self.size -= 1
    
    def output_singly_linked_list(self) -> None:
        cur_node = self.head
        while cur_node is not None:
            print(cur_node.val)
            cur_node = cur_node.next


if __name__ == '__main__':
    my_linkedlist = SinglyLinkedList()
    my_linkedlist.addAtTail(5)
    my_linkedlist.addAtTail(2)
    my_linkedlist.addAtTail(6)
    my_linkedlist.addAtTail(1)
    my_linkedlist.addAtHead(4)

    my_linkedlist.output_singly_linked_list()