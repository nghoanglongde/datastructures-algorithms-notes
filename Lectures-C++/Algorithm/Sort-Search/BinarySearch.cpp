#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

//chặt nhị phân thông thường
bool BS(vector<int> nums, int target){
    int n = nums.size();
    int left = 0;
    int right =  target;
    int mid = (left + right) / 2;
    while (left != mid && right != mid)
    {
        if(nums[mid] <= target){
            left = mid;
        }
        else
            right = mid;
        mid = (left + right) / 2;
    }
    return (nums[mid] == target) ? true : false;
}

//chặt nhị phân sử dụng thư viện có sẵn
bool BSLib(vector<int> nums, int target){
    auto k = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    if (k < nums.size() && nums[k] == target) {
        return true;
    }
}

int main()
{
    //Tìm số trong mảng tăng dần
    vector<int> nums;
    int n, target;
    cin >> n >> target;
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    
    BSLib(nums, target);

    if(BS(nums, target)){
        cout << "Found" << endl;
    }
    else{
        cout << "Not found" << endl;
    }
}