# Link: https://leetcode.com/problems/top-k-frequent-elements/
# Site: LeetCode
# Name: Top K frequent elements
# Medium
# ======================================================

# Time Complexity: O(nlogn)
# Space Complexity: O(n)

class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        frequent_dict = {}
        for value in nums:
            if value in frequent_dict:
                frequent_dict[value] += 1
            else:
                frequent_dict[value] = 1
        sorted_li = sorted(frequent_dict.items(), key=lambda x: x[1], reverse=True)
        return [item[0] for item in sorted_li[:k]]