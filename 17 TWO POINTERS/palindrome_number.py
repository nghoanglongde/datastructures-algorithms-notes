# Link: https://leetcode.com/problems/palindrome-number/
# Site: LeetCode
# Name: Palindrome Number
# Easy
# ======================================================

# Time Complexity: O(n)
# Space Complexity: O(2 + n) = O(n)

class Solution:
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        x = str(x)
        for i in range(len(x) // 2):
            left_point = x[i]
            right_point = x[len(x) - i - 1]
            if left_point != right_point:
                return False
        return True
