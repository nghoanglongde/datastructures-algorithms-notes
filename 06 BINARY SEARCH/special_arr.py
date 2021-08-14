# Link: https://leetcode.com/problems/special-array-with-x-elements-greater-than-or-equal-x/
# Site: LeetCode
# Name: Special Array With X Elements Greater Than or Equal X
# Easy
# ======================================================

# Time Complexity: O(nlogn)
# Space Complexity: O(1)

import bisect

class Solution:
    def specialArray(self, nums) -> int:
        nums = sorted(nums)
        res = -1
        for i in range(len(nums) + 1):
            idx = bisect.bisect_left(nums, i)
            if idx == len(nums):
                continue
            else:
                num_left = len(nums) - idx
                if num_left == i:
                    res = num_left
                    break 
        return res 

    