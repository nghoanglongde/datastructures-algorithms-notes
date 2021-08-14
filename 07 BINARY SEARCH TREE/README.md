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
        self.left = None
        self.value = value
        self.right = None
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
    elif root.value > value:
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
    elif root.value < target:
        root.right = delete_node(root.right, target)
    elif root.value > target:
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
        root.value = temp.value
        root.right = delete_node(root.right, temp.value)
    return root
```

# Another method to work with BST

## Traversal

### Inorder traversal

Time complexity: O(n), n = number of node

traversal: LEFT -> ROOT -> RIGHT
```python
# Space Complexity: O(1), print out the result line by line

def inorder_traverse(root):
    if root is not None:
        inorder_traverse(root.left)
        print(root.value)
        inorder_traverse(root.right)
```

```python
# Space Complexity: O(n), return the result in the array

def inorder_traverse(root):
    if root is None: return []
    left = self.inorderTraversal(root.left)
    right = self.inorderTraversal(root.right)
    return left + [root.val] + right
```
### Preorder traversal

Time complexity: O(n), n = number of node

traversal: ROOT -> LEFT -> RIGHT
```python
# Space Complexity: O(1), print out the result line by line

def preorder_traverse(root):
    if root is not None:
        print(root.value)
        preorder_traverse(root.left)
        preorder_traverse(root.right)
```

```python
# Space Complexity: O(n), return the result in the array

def preorder_traverse(root):
    if root is None: return []
    left = self.inorderTraversal(root.left)
    right = self.inorderTraversal(root.right)
    return [root.val] + left + right
```


### Postorder traversal

Time complexity: O(n), n = number of node

traversal: LEFT -> RIGHT -> ROOT
```python
# Space Complexity: O(1), print out the result line by line

def postorder_traverse(root):
    if root is not None:
        preorder_traverse(root.left)
        preorder_traverse(root.right)
        print(root.value)
```

```python
# Space Complexity: O(n), return the result in the array

def postorder_traverse(root):
    if root is None: return []
    left = self.inorderTraversal(root.left)
    right = self.inorderTraversal(root.right)
    return left + right + [root.val]
```

## Height of BST

Time complexity: O(n)

Base on assumption you want:
+ Height as edge count (height at root = 0, maximize number of node in BST = 2^(h + 1) - 1)
+ Height as node count (height at root = 1, maximize number of node in BST = 2^h - 1)

```python
# edge count
def height_tree(root):
    if (root is None) or (root.left is None and root.right is None):
        return 0
    else:
        left_h = height_tree(root.left)
        right_h = height_tree(root.right)
        max_h = max(left_h, right_h)
        return max_h + 1
```
```python
# node count
def height_tree(root):
    if root is None:
        return 0
    else:
        left_h = height_tree(root.left)
        right_h = height_tree(root.right)
        max_h = max(left_h, right_h)
        return max_h + 1
```

## Delete BST

Time complexity: O(n)

```python
def delete_tree(root):
    if root is None:
        return
    else:
        delete_tree(root.left)
        delete_tree(root.right)
        del root
```

## Practice

[Binary Tree Inorder Traversal](https://github.com/nghoanglong/DataStructures-Algorithms-CheatSheet/blob/master/07%20BINARY%20SEARCH%20TREE/inorder_traversal.py)

[Maximum Depth of Binary Tree](https://github.com/nghoanglong/DataStructures-Algorithms-CheatSheet/blob/master/07%20BINARY%20SEARCH%20TREE/maximum_depth.py)
