# Link: https://leetcode.com/problems/intersection-of-two-arrays-ii/
# Site: LeetCode
# Name: Intersection of Two Arrays II
# Easy
# ======================================================

class Solution:
    def intersection(self, nums1: 'list[int]', nums2: 'list[int]') -> 'list[int]':
        table = {}
        res = []
        for value in nums1:
            if value in table:
                table[value] += 1
            else:
                table[value] = 1
                
        for value in nums2:
            if value in table and table[value]:
                res.append(value)
                table[value] -= 1
        return res