/*
    Bài toán: Cho một mảng n phần tử, đếm số mảng con có các phần tử liên tiếp có tổng nhỏ hơn hoặc bằng k

    Idea:
    B1: Sử dụng 2 con trỏ, sử dụng con trỏ end trượt ngang theo các phần tử mảng để cộng dồn vào một biến sum
    B2: Trường hợp sum > target và con trỏ start < end(nếu start == end thì phần tử tại đó tự trừ cho chính nó là ko đc), 
    ta cho con trỏ left di chuyển tới vị trí tiếp theo, di chuyển cho đến khi sum - arr[left] <= target
    B3: cập nhật lại ans

    Đpt: O(2*n)

*/
#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

typedef long long ll;

int main(){
    ifstream fi;
    fi.open("SASLTK-Part2.txt");
    if(!fi){
        cout << "Cant open this file" << endl;
        return 0;
    }
    ll t; fi >> t;
    while(t--){
        ll n, target; 
        fi >> n >> target;
        vector<ll> arr(n);
        for(ll i = 0;i < n;i++){ 
            fi >> arr[i];
        }
        ll start = 0, end = 0, sum = 0, ans = 0;
        while(end < n){
            sum = sum + arr[end];
            while(start < end && sum > target){
               //nếu lớn hơn target -> ta cần giảm tổng xuống sao cho <= target
               sum = sum - arr[start];
               ++start;
            }
            if(sum <= target)
                ans = ans + (end - start + 1);
            ++end;
        }
        cout << ans << endl;
    }
}