//Link: https://leetcode.com/problems/maximum-subarray/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int best = (int)-1e9;
        for(int i = 0;i < nums.size();i++){
            sum = max(nums[i], sum + nums[i]);
            best = max(best, sum);
        }
        return (best == (int)-1e9) ? nums[0] : best;
    }
};