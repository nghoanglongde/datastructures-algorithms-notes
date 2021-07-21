# Link: https://leetcode.com/problems/search-in-rotated-sorted-array/
# Site: LeetCode
# Name: Search in Rotated Sorted Array
# Medium
# ======================================================

class Solution:
    def search(self, nums: list, target: int) -> int:
        left = 0
        right = len(nums) - 1
        mid = left + (right - left) // 2
        while left != mid and right != mid:
            if nums[mid] < nums[right]:
                if target >= nums[mid] and target <= nums[right]:
                    left = mid
                else:
                    right = mid
            else:
                if target <= nums[mid] and target >= nums[left]:
                    right = mid
                else:
                    left = mid
            mid = left + (right - left) // 2
        if nums[left] == target:
            return left
        elif nums[right] == target:
            return right
        else:
            return -1
        

if __name__ == '__main__':
    sol = Solution()
    li = [4,5,6,7,0,1,2]
    target = 2
    res = sol.search(li, target)
    print(res)
