# Link: https://leetcode.com/problems/same-tree/
# Site: LeetCode
# Name: Same Tree
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
    def isSameTree(self, p: Optional[TreeNode], q: Optional[TreeNode]) -> bool:
        queue = [(p, q)]
        while len(queue) != 0:
            node_p, node_q = queue.pop(0)
            if not node_p and not node_q:
                continue
            elif not node_p or not node_q:
                return False
            elif node_p.val == node_q.val:
                queue.append((node_p.left, node_q.left))
                queue.append((node_p.right, node_q.right))
            else:
                return False
        return True