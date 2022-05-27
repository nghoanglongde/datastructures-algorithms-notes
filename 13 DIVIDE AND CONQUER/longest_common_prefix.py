# Link: https://leetcode.com/problems/longest-common-prefix/
# Site: LeetCode
# Name: Longest Common Prefix
# Easy
# ======================================================

# Time Complexity: O(nlogn)
# Space Complexity: O(logn)

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        def process_res(strs, left, right):
            if left == right:
                return strs[left]
            else:
                mid = (left + right) // 2
                str_left = process_res(strs, left, mid)
                str_right = process_res(strs, mid + 1, right)
                return commonstr(str_left, str_right)
        
        def commonstr(str_left, str_right):
            min_val = min(len(str_left), len(str_right))
            for i in range(min_val):
                if str_left[i] != str_right[i]:
                    return str_left[:i]
            return str_left[:min_val]
            
        return process_res(strs, 0, len(strs) - 1)
            