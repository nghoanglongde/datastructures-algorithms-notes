# Link: https://leetcode.com/problems/running-sum-of-1d-array/
# Site: LeetCode
# Name: Running Sum of 1d Array
# Easy
# ======================================================

# Time Complexity: O(n)
# Space Complexity: O(n)

class Solution:
    def runningSum(self, nums: List[int]) -> List[int]:
        prefix_sum = [nums[0]]
        for idx, value in enumerate(nums):
            if idx != 0:
                sum = prefix_sum[idx - 1] + value
                prefix_sum.append(sum)
        return prefix_sum       