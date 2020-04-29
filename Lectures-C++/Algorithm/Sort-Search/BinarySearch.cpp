#include <iostream>
#include <vector>
using namespace std;

int mySqrt(int x) {
    long long left = 0;
    long long right = x;
    long long mid = (left + right) / 2;
    while (left != mid && right != mid)
    {
        if(mid * mid <= x){
            left = mid;
        }
        else
            right = mid;
        mid = (left + right) / 2;
    }
    return (right * right == x) ? right : left; //trường hợp căn 1
}

bool BS(vector<int> nums, int target){
    //Binary Search tìm số trong mảng tăng dần
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
    return (nums[left] == target || nums[right] == target) ? true : false;
}

int main()
{
    //Tìm số trong mảng tăng dần
    vector<int> nums;
    int n, target;
    cin >> n;
    cin >> target;
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        nums.push_back(temp);
    }
    if(BS(nums, target)){
        cout << "Found" << endl;
    }
    else{
        cout << "Not found" << endl;
    }

    //tìm căn bậc 2 bằng binary search ko sử dụng lib
    int num_sqrt;
    cin >> num_sqrt;
    int result_sqrt = mySqrt(num_sqrt);
    cout << result_sqrt;
}