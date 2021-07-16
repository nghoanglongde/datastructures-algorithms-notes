# Binary Search Tree

## Define

Binary search tree (BST) is a node-based binary tree data structure which has some following properties:
+ The left subtree of the current node contain only nodes have value less than the current node
+ The right subtree of the current node contain only nodes have value greater than the current node
+ Each current node has only two child nodes

## Structure of a node

Time complexity: O(1)
```python
class Node:
    def __init__(self, value):
        left_node = None
        value = value
        right_node = None
```

## Create a new node

Time complexity: O(1)

```python
def create_node(value):
    new_node = Node(value)
    return new_node
```

## Insert a node to BST

Time complexity: O(h) with h is the height of the tree, worst case is all nodes in the left subtree or right subtree, then we have O(n) to insert new node to BST
```python
def insert_node(root, value):
    if root is None:
        new_node = Node(value)
        return new_node
    elif root.key > new_node.key:
        root.left = insert_node(root.left, value)
    else:
        root.right = insert_node(root.right, value)
    return root
```

## Create BST from a List

Time complexity: O(n*h), n is the lenght of the list and h is the height of the tree

```python
def create_BST(li):
    root = None
    for value in li:
        root = insert_node(root, value)
    return root
```

## Find the target value in BST

Time complexity: O(h) with h is the height of the tree, worst case is all nodes in the left subtree or right subtree, then we have O(n) to traverse the tree to find the target value

```python
def find_node(root, target):
    if root == None or root.value == target:
        return root
    elif root.value < target:
        return find_node(root.right, target)
    return find_node(root.left, target)
```

## Delete the target value in BST

Time complexity: O(h) with h is the height of the tree, worst case is all nodes in the left subtree or right subtree, then we have O(n) to traverse the tree to find and delete the target value

We need consider three cases:
+ The target value is the leave of the tree
+ The target value is the node which have one or two child nodes
+ The target value is the root (its the same case when we want to delete the node which have two child nodes)

In the case we want delete the node which have two child nodes, we need to find the suitable node to replace that position. So, we have two ways to find that suitable node
+ find the node has minimize value in the right subtree
+ find the node has maximize value in the left subtree

In this tutorial, I refer to use the first way

```python
# find the node has minimize value in the right subtree
def minValueNode(root):
    cur = root
    while cur.left != None:
        cur = cur.left
    return cur
```

```python
# delete the target value in the tree
def delete_node(root, target):
    if root is None:
        return root
    elif root.key < target:
        root.right = delete_node(root.right, target)
    elif root.key > target:
        root.left = delete_node(root.left, target)
    else:
        if root.left is None:
            temp = right
            del root
            return temp
        elif root.right is None:
            temp = left
            del root
            return temp
        temp = minvalueNode(root.right)
        root.key = temp.key
        root.right = delete_node(root.right, temp.key)
    return root
```

# Another method to work with BST

## Traversal

### Inorder traversal

### Preorder traversal

### Postorder traversal
