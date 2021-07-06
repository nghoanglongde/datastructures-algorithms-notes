# Doubly-linked list implementation
class Node:
    def __init__(self, value: int) -> None:
        self.prev = None
        self.val = value
        self.next = None

class DoublyLinkedList:
    def __init__(self) -> None:
        self.head = None
        self.tail = None
        self.size = 0

    def addAtTail(self, value: int) -> None:
        new_node = Node(value)
        if self.head is None:
            self.head = new_node
            self.tail = self.head
        else:
            self.tail.next = new_node
            new_node.prev = self.tail
            self.tail = new_node
        self.size += 1

    def addAtHead(self, value: int) -> None:
        new_node = Node(value)
        if self.head is None:
            self.head = new_node
            self.tail = self.head
        else:
            new_node.next = self.head
            self.head.prev = new_node
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
                self.addAtTail()
            else:
                cur = self.head
                for i in range(0, index - 1):
                    cur = cur.next
                new_node.prev = cur
                new_node.next = cur.next
                cur.next.prev = new_node
                cur.next = new_node
            self.size += 1
    
    def deleteAtHead(self) -> None:
        if self.head.next is None:
            self.head = None
        else:
            self.head = self.head.next
            self.head.prev = None
        self.size -= 1
    
    def deleteAtTail(self) -> None:
        if self.tail.prev is None:
            self.head = None
            self.tail = self.head
        else:
            self.tail = self.tail.prev
            self.tail.next = None
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
                # 5 2 6 1
                cur = self.head
                for i in range(0, index - 1):
                    cur = cur.next
                cur.next = cur.next.next
                cur.next.prev = cur
            self.size -= 1

    def output_doubly_linked_list(self, backward=False) -> None:
        if backward:
            cur_node = self.tail
            while cur_node is not None:
                print(cur_node.val)
                cur_node = cur_node.prev
        else:
            cur_node = self.head
            while cur_node is not None:
                print(cur_node.val)
                cur_node = cur_node.next

if __name__ == '__main__':
    my_linkedlist = DoublyLinkedList()
    my_linkedlist.addAtTail(5)
    my_linkedlist.addAtTail(2)
    my_linkedlist.addAtTail(6)
    my_linkedlist.addAtTail(1)
    my_linkedlist.deleteAtIndex(2)

    my_linkedlist.output_doubly_linked_list()
    print("=================================================")
    my_linkedlist.output_doubly_linked_list(backward=True)