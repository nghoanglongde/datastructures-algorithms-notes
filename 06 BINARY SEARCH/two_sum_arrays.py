# Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
# Site: LeetCode
# Name: Two Sum II - Input array is sorted
# Easy
# ======================================================

import bisect

class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        for idx, value in enumerate(numbers):
            ano_value = target - value
            idx_ano = bisect.bisect_left(numbers, ano_value, idx + 1, len(numbers))
            if idx_ano != len(numbers):
                if value + numbers[idx_ano] == target:
                    return [idx + 1, idx_ano + 1]
