# Link: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
# Site: LeetCode
# Name: Convert Sorted List to Binary Search Tree
# Medium
# ======================================================

# Time Complexity: O(n), with n = number of node
# Space Complexity: O(n), with n = number of node

# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def transfer_toBST(self, li):
        if len(li) == 0:
            return None
        else:
            mid = len(li) // 2
            node = TreeNode(li[mid])
            node.left = self.transfer_toBST(li[:mid])
            node.right = self.transfer_toBST(li[mid+1:])
        return node
            
    def sortedListToBST(self, head: Optional[ListNode]) -> Optional[TreeNode]:
        # convert linked list to array
        li_nodes = []
        while head:
            li_nodes.append(head.val)
            head = head.next
        
        # transfer array to tree
        return self.transfer_toBST(li_nodes)
        
        
        