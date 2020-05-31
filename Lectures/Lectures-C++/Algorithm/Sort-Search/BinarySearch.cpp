#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

//chặt nhị phân thông thường
bool BS(vector<int> nums, int target){
    int n = nums.size();
    int left = 0;
    int right =  n - 1;
    int mid = (left + right) / 2;
    while (left != mid && right != mid)
    {
        if(nums[mid] < target){
            //chặt nhị phân trên mảng tăng dần(hoặc giảm dần thì đổi dấu < thành dấu > giữ nguyên ruột bên trong)
            //nếu sử dụng dấu < thì sẽ trả về vị trí nhỏ nhất mà tại đó >= target(đối với mảng tăng dần, còn mảng giảm dần thì là <= target)
            //còn nếu sử dụng dấu <= thì vòng for ở dưới phải chạy từ right -> left. nó sẽ trả về vị trí lớn nhất mà tại đó >= target
            //nếu ko tìm thấy có vị trí nào >= target -> target lớn hơn mọi số trong mảng(đối với mảng tăng dần, còn mảng giảm dần thì target nhỏ
            //hơn mọi số trong mảng)
            left = mid;
        }
        else
            right = mid;
        mid = (left + right) / 2;
    }
    bool flag = false;
    int pos;
    for(pos = left;pos <= right;pos++){
        if(nums[pos] >= target){
            flag = true;
        }
    }
    return flag;
}

chặt nhị phân sử dụng thư viện có sẵn
bool BSLib(vector<int> nums, int target){
    auto k = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
    //upper_bound -> trả về số lớn hơn target
    //lower_bound -> trả về số lớn hơn hoặc bằng target
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