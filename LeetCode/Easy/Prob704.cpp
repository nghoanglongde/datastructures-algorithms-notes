class Solution {
public:
    //dùng cách left != i and right != i ta sẽ tránh trường hợp left luôn luôn <= right do cách nhau 1 -> ví dụ [2, 5] -> tìm key 5
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int i = (left + right) / 2;
        while(left != i && right != i){
            if(nums[i] <= target)
                left = i;
            else
                right = i;
            i = (left + right) / 2;
        }
        if(nums[left] == target){
            return left;
        }
        else if(nums[right] == target){
            return right;
        }
        else{
            return -1;
        }
    }
};