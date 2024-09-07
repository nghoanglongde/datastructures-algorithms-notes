# Link: https://leetcode.com/problems/maximum-average-subarray-i/
# Site: Leetcode
# Name: Maximum Average Subarray I
# Easy
# ======================================================
# Time complexity: O(n)
# Space complexity: O(1)

class Solution:
    def findMaxAverage(self, nums, k) -> float:
        start_p = 0
        max_average = float('-inf')
        sum_value = 0

        for end_p in range(len(nums)):
            sum_value += nums[end_p]

            if end_p >= k - 1:
                max_average = max(max_average, sum_value / k)
                sum_value -= nums[start_p]
                start_p += 1
        return max_average

# if __name__ == '__main__':
#     a = Solution().findMaxAverage([1,12,-5,-6,50,3], 4)
#     print(a)
    