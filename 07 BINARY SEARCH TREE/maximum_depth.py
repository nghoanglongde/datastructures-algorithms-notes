# Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/
# Site: LeetCode
# Name: Maximum Depth of Binary Tree
# Easy
# ======================================================

# Time Complexity: O(n)
# Space Complexity: O(1)

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        if root is None: return 0
        else:
            left_height = self.maxDepth(root.left)
            right_height = self.maxDepth(root.right)
            max_height = max(left_height, right_height)
            return 1 + max_height
            