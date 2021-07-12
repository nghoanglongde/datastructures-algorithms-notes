# Link: https://leetcode.com/problems/max-consecutive-ones/
# Name: Max Consecutive Ones
# Site: LeetCode
# Easy
# ======================================================

class Solution:
    def findMaxConsecutiveOnes(self, nums: 'list[int]') -> int:
        sum = 0
        max_num = 0
        for value in nums:
            if value == 1:
                sum += 1
            else:
                max_num = max(max_num, sum)
                sum = 0
        max_num = max(max_num, sum)
        return max_num