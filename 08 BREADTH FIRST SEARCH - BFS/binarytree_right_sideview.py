# Link: https://leetcode.com/problems/binary-tree-right-side-view/
# Site: LeetCode
# Name: Binary Tree Right Side View
# Medium
# ======================================================

# Time Complexity: O(n), with n = number of node
# Space Complexity: O(n + m), with n = number of node in res and m is the number of nodes in the tree

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        res = []
        if root:
            queue = [root]
            res.append(root.val)
            while len(queue) > 0:
                check = False
                len_queue = len(queue)
                for _ in range(len_queue):
                    curr = queue.pop(0)
                    node_right = curr.right
                    node_left = curr.left
                    if node_right:
                        queue.append(node_right)
                        if not check:
                            check = True
                            res.append(node_right.val)
                    if node_left:
                        queue.append(node_left)
                        if not check:
                            check = True
                            res.append(node_left.val)
        return res