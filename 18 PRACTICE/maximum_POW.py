# Link: https://leetcode.com/problems/maximum-product-of-word-lengths/
# Site: LeetCode
# Name: Maximum Product of Word Lengths
# Medium
# ======================================================

# Time Complexity: O(n^2)
# Space Complexity: O(n)

class Solution:
    def maxProduct(self, words: List[str]) -> int:
        words_preprocessed = []
        for word in words:
            words_preprocessed.append([set(word), len(word)])
        
        max_len = 0
        for i in range(len(words)):
            for j in range(i + 1, len(words)):
                if words_preprocessed[i][0].isdisjoint(words_preprocessed[j][0]):
                    max_len = max(max_len, words_preprocessed[i][1] * words_preprocessed[j][1])
        return max_len