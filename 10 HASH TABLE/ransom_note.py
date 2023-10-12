# Link: https://leetcode.com/problems/ransom-note/description/
# Site: LeetCode
# Name: Ransom Note
# Easy
# ======================================================

# Time Complexity: O(m = ransom_note len + n = magazine len)
# Space Complexity: O(m + n)

class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        ransom_note = Counter(ransomNote)
        magazine = Counter(magazine)

        for key, value in ransom_note.items():
            if key not in magazine:
                return False
            else:
                if value > magazine[key]:
                    return False
        return True