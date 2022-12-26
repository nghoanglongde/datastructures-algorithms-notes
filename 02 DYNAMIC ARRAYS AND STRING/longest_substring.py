# Link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
# Name: Longest Substring Without Repeating Characters
# Site: LeetCode
# Medium
# ======================================================

# Brute force
# TC: O(n^2)
# SC: O(1)
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        max_len = 0
        for i in range(len(s)):
            temp = {}
            for j in range(i, len(s)):
                if s[j] not in temp:
                    temp[s[j]] = 1
                    max_len = max(max_len, len(temp))
                else:
                    max_len = max(max_len, len(temp))
                    break
        return max_len

# Sliding window
# TC: O(2n)
# SC: O(n)
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        max_len = 0
        left = right = 0
        tmp = {}
        while right < len(s):
            if s[right] not in tmp:
                tmp[s[right]] = 1
            else:
                tmp[s[right]] += 1
                while tmp[s[right]] > 1:
                    tmp[s[left]] -= 1
                    left += 1
            max_len = max(max_len, right - left + 1)
            right += 1
        return max_len