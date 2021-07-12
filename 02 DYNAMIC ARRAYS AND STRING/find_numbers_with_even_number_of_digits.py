# Link: https://leetcode.com/problems/find-numbers-with-even-number-of-digits/
# Name: Find Numbers with Even Number of Digits
# Site: LeetCode
# Easy
# ======================================================

class Solution:
    def findNumbers(self, nums: 'list[int]') -> int:
        res = list(filter(lambda x: len(str(x)) % 2 == 0, nums))
        return len(res)

        # another way speed up time than using filter
        # return sum([1 if len(str(num)) % 2 == 0 else 0 for num in nums])