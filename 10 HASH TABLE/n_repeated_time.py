# Link: https://leetcode.com/problems/n-repeated-element-in-size-2n-array/
# Site: LeetCode
# Name: N-Repeated Element in Size 2N Array
# Easy
# ======================================================

# Time Complexity: O(n)
# Space Complexity: O(n)

class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        dic = {}
        for value in nums:
            if value not in dic:
                dic[value] = 1
            else:
                return value