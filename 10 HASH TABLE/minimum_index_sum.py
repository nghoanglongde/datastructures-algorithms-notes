# Link: https://leetcode.com/problems/minimum-index-sum-of-two-lists/
# Site: LeetCode
# Name: Minimum Index Sum of Two Lists
# Easy
# ======================================================

# Time Complexity: O(n + m)
# Space Complexity: O(n)

class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        dic_1 = {value: idx for idx, value in enumerate(list1)}
        
        least_index = math.inf
        for idx, value in enumerate(list2):
            if value in dic_1:
                if dic_1[value] + idx < least_index:
                    res = [value]
                    least_index = dic_1[value] + idx
                elif dic_1[value] + idx == least_index:
                    res.append(value)
        return res
