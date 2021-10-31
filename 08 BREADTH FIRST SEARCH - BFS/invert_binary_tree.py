# Link: https://leetcode.com/problems/invert-binary-tree/
# Site: LeetCode
# Name: Invert Binary Tree
# Easy
# ======================================================

# Time Complexity: O(n), with n = number of node
# Space Complexity: O(n), with n = number of node


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if root:
            queue = [root]
            while len(queue) != 0:
                len_queue = len(queue)
                for _ in range(len_queue):
                    curr = queue.pop(0)
                    node_left = curr.left
                    node_right = curr.right
                    if curr.right:
                        queue.append(node_right)
                    if curr.left:
                        queue.append(node_left)
                    curr.right = node_left
                    curr.left = node_right
        return root
            