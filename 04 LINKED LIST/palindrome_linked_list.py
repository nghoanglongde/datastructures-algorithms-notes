# Link: https://leetcode.com/problems/palindrome-linked-list/
# Site: LeetCode
# Name: Palindrome Linked List
# Easy
# ======================================================
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def getHeadOfSecondPart(self, head: ListNode) -> ListNode:
        slow = fast = head
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        if fast is None:
            return slow
        else:
            return slow.next
    def isPalindrome(self, head: ListNode) -> bool:
        head_second_part = self.getHeadOfSecondPart(head)
        head_firt_part = head

        # reverse second part
        prev_node = None
        cur_node = head_second_part
        while cur_node is not None:
            next_node = cur_node.next
            cur_node.next = prev_node
            prev_node = cur_node
            cur_node = next_node
        head_second_part = prev_node

        
        while head_second_part is not None:
            if head_firt_part.val != head_second_part.val:
                return False
            head_firt_part = head_firt_part.next
            head_second_part = head_second_part.next
        return True 
        