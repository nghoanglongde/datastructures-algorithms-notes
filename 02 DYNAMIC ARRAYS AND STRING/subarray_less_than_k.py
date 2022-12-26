# Link: https://leetcode.com/problems/subarray-product-less-than-k
# Site: LeetCode
# Name: Subarray Product Less Than K
# Medium
# ======================================================

# Sliding window
# TC: O(n)
# SP: O(1)
class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        left = right = 0
        prod = 1
        ans = 0
        if len(nums) == 0 or k <= 1:
            return 0
        while right <= len(nums) - 1:
            prod *= nums[right]
            if prod >= k:
                while prod >= k:
                    prod /= nums[left]
                    left += 1
            ans += (right - left) + 1
            right += 1
        return ans

