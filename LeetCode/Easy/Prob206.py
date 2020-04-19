class node:
    def __init__(self, data):
        self.next = None
        self.data = data


class SingleLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    def Push(self, data):
        new_node = node(data)
        if self.head is None:
            self.head = new_node
            self.tail = self.head
        else:
            self.tail.next = new_node
            self.tail = new_node

    def printList(self):
        current = self.head
        while current is not None:
            print(current.data, end=' ')
            current = current.next

    def ReverseLinkedList(self):
        current = None
        previous = None
        while self.head is not None:
            current = self.head
            self.head = self.head.next
            current.next = previous
            previous = current

        self.head = current


def main():
    n = int(input())
    ListNode = SingleLinkedList()
    for i in range(n):
        data = int(input())
        ListNode.Push(data)

    ListNode.ReverseLinkedList()
    ListNode.printList()

main()
