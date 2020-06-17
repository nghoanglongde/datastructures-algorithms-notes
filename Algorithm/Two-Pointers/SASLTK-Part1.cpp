/*
    
    Bài toán: Cho một mảng n phần tử, tìm một mảng các phần tử liên tiếp có tổng lớn nhất, nhưng ko được lớn hơn M, in ra tổng lớn nhất
    tìm được

    Idea: 
    B1: Tính tổng dãy các phần tử dài nhất có thể sao cho sum <= target 
    B2: cập nhật max sum <= target có thể có được
    B3: tiến hành giảm phần tử bên trái để ta có thể tiếp tục thêm vào tổng phần tử tiếp theo của con trỏ bên phải cho đến khi right >= n

    Đpt: O(2*n)
    
*/
#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

typedef long long ll;

int main(){
    ifstream fi;
    fi.open("SASLTK-Part1.txt");
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
        ll ans = (ll)-1e8;
        ll left = 0, right = 0, sum = 0;
        while(left < n){
            while(right < n && sum + arr[right] <= target){
                sum = sum + arr[right];
                ++right;
            }
            ans = max(ans, sum);
            sum = sum - arr[left];
            ++left;
        }
        cout << ans << endl;
    }
}