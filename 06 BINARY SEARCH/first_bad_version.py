# Link: https://leetcode.com/problems/first-bad-version/
# Site: LeetCode
# Name: First Bad Version
# Easy
# ======================================================


# The isBadVersion API is already defined for you.
# def isBadVersion(version: int) -> bool:

class Solution:
    def firstBadVersion(self, n: int) -> int:
        left = 1
        right = n
        mid = left + (right - left) // 2
        while left != mid and right != mid:
            if isBadVersion(mid):
                right = mid
            else:
                left = mid
            mid = left + (right - left) // 2
        if isBadVersion(left):
            return left
        return right