# Link: https://leetcode.com/problems/find-pivot-index/
# Site: LeetCode
# Name: Find Pivot Index
# Easy
# ======================================================

# Time Complexity: O(n)
# Space Complexity: O(1)

class Solution:
    def pivotIndex(self, nums: List[int]) -> int:
        total_sum = sum(nums)
        left_sum = 0
        for idx, value in enumerate(nums):
            right_sum = total_sum - (left_sum + value)
            if right_sum == left_sum:
                return idx
            left_sum += value
        return -1
            
            