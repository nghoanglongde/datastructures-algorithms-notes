# Link: https://leetcode.com/problems/merge-sorted-array/
# Name: Merge Sorted Array
# Site: LeetCode
# Easy
# ======================================================

class Solution:
    def merge(self, nums1: 'list[int]', m: int, nums2: 'list[int]', n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        while m > 0 and n > 0:
            if nums1[m - 1] >= nums2[n - 1]:
                nums1[m + n - 1] = nums1[m - 1]
                m -= 1
            else:
                nums1[m + n -1] = nums2[n - 1]
                n -= 1
        if n > 0:
            # if all elements of nums2 haven't merged
            nums1[:n] = nums2[:n]


        