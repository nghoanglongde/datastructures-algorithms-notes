# Link: https://leetcode.com/problems/keyboard-row/
# Name: Keyboard Row
# Site: LeetCode
# Easy
# ======================================================

class Solution:
    def findWords(self, words: List[str]) -> List[str]:
        res = list(filter(lambda word: set(word.lower()).issubset(set("qwertyuiop")) or
                                         set(word.lower()).issubset(set("asdfghjkl")) or
                                         set(word.lower()).issubset(set("zxcvbnm")), words))
        return res