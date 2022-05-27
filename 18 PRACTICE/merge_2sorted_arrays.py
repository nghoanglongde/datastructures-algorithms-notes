# Link: https://leetcode.com/problems/merge-sorted-array/
# Site: LeetCode
# Name: Merge Sorted Array
# Easy
# ======================================================

# Time Complexity: O(n)
# Space Complexity: O(n)

class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        temp = []
        pt_nums1 = pt_nums2 = 0

        while pt_nums1 <= m - 1 or pt_nums2 <= n - 1:
            if pt_nums1 > m - 1:
                temp.append(nums2[pt_nums2])
                pt_nums2 += 1
            elif pt_nums2 > n - 1:
                temp.append(nums1[pt_nums1])
                pt_nums1 += 1
            elif nums1[pt_nums1] < nums2[pt_nums2]:
                temp.append(nums1[pt_nums1])
                pt_nums1 += 1
            elif nums2[pt_nums2] < nums1[pt_nums1]:
                temp.append(nums2[pt_nums2])
                pt_nums2 += 1
            elif nums1[pt_nums1] == nums2[pt_nums2]:
                temp.append(nums1[pt_nums1])
                temp.append(nums2[pt_nums2])
                pt_nums1 += 1
                pt_nums2 += 1

        for idx in range(len(temp)):
            nums1[idx] = temp[idx]