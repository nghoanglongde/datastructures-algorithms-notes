#Binary Search Tree viết theo function programming kết hợp class, ngoài ra có thể viết OOP thuần
class NODES:
    def __init__(self, value):
        self.value = value
        self.node_left = None
        self.node_right = None


def inputNode(root, value):
    if(root is None):
        root = NODES(value)
        return root
    else:
        if root.value <= value:
            root.node_right = inputNode(root.node_right, value)
        else:
            root.node_left = inputNode(root.node_left, value)
    return root


def outputTree(root):
    if root is None:
        return
    else:
        print(root.value)
        outputTree(root.node_left)
        outputTree(root.node_right)


def main():
    num_nodes = int(input('Nhap so nodes: '))
    root = None
    for i in range(1, num_nodes + 1):
        value_node = int(input(f'Gia tri cua node {i}: '))
        root = inputNode(root, value_node)
    outputTree(root)


main()
