/*

    Bài toán: Cho 2 mảng A và B đã được sắp xếp tăng dần(A và B có số lượng phần tử bất kì, có thể bằng nhau hoặc ko), trộn 2 danh sách
    này thành 1 danh sách sao cho nó vẫn giữ tính chất mảng tăng

    Idea: Sử dụng 2 con trỏ l1 and l2. L1 sẽ duyệt tại mảng thứ nhất và l2 sẽ duyệt tại mảng thứ 2
    
    .Nếu l1 < arr_1.size() && l2 < arr.size() -> tiến hành so sánh giá trị của 2 con trỏ này đang nắm giữ, phần tử nhỏ hơn -> đưa vào mảng 
    ans(answer) -> đưa con trỏ lên vị trí tiếp theo
    .Nếu l2 > arr_2.size() -> tiến hành đưa phần tử con trỏ l1 đang nắm giữ vào mảng ans -> đưa con trỏ l1 lên vị trí tiếp theo
    .Tương tự l1

    Đpt: O(arr_1.size() + arr_2.size())
*/

#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

typedef long long ll;

void solve(vector<ll> arr1, vector<ll> arr2, ll size_arr1, ll size_arr2){
    vector<ll> ans;
    ll ptr_arr1 = 0;
    ll ptr_arr2 = 0;
    while(ptr_arr1 < size_arr1 || ptr_arr2 < size_arr2){
        if(ptr_arr1 < size_arr1 && ptr_arr2 < size_arr2){
            if(arr1[ptr_arr1] <= arr2[ptr_arr2]){
                ans.push_back(arr1[ptr_arr1]);
                ++ptr_arr1;
            }
            else{
                ans.push_back(arr2[ptr_arr2]);
                ++ptr_arr2;
            }
        }
        else if(ptr_arr1 < size_arr1){
            ans.push_back(arr1[ptr_arr1]);
            ++ptr_arr1;
        }
        else if(ptr_arr2 < size_arr2){
            ans.push_back(arr2[ptr_arr2]);
            ++ptr_arr2;
        }
    }
    for(auto x: ans){
        cout << x << " ";
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ifstream fi;
    fi.open("MergeTwoSortedList.txt");
    if(!fi){
        cout << "Cant open this file" << endl;
        return 0;
    }
    ll t; fi >> t;
    while(t--){
        //Input 2 mảng đã sort tăng dần   
        ll size_arr1, size_arr2; 
        fi >> size_arr1;
        vector<ll> arr1(size_arr1);
        for(ll i = 0;i < size_arr1;++i){
            fi >> arr1[i];
        }     
        fi >> size_arr2;
        vector<ll> arr2(size_arr2);
        for(ll i = 0;i < size_arr2;++i){
            fi >> arr2[i];
        }
        solve(arr1, arr2, size_arr1, size_arr2);
    }
}