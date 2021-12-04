# Link: https://leetcode.com/problems/largest-substring-between-two-equal-characters/
# Site: LeetCode
# Name: Largest Substring Between Two Equal Characters
# Easy
# ======================================================

# Time Complexity: O(n)
# Space Complexity: O(n)

class Solution:
    def maxLengthBetweenEqualCharacters(self, s: str) -> int:
        max_diff = -1
        dic = {}
        for idx, value in enumerate(s):
            if value not in dic:
                dic[value] = idx
            elif idx - dic[value] - 1 > max_diff:
                max_diff = idx - dic[value] - 1
        return max_diff