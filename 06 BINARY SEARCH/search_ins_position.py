# Link: https://leetcode.com/problems/search-insert-position/
# Site: LeetCode
# Name: Search Insert Position
# Easy
# ======================================================

import bisect

class Solution:
    def searchInsert(self, nums: 'list[int]', target: int) -> int:
        return bisect.bisect_left(nums, target, 0, len(nums))