/*

Bài toán: Cho một mảng A sắp xếp tăng dần, có n phần tử. Tìm bất cứ cặp pair(i, j) nào có tổng bằng X cho trước 

Idea:
1. Lặp qua từng phần tử A[i], nếu trong A có phần tử X - A[i] với j != i thì xuất ra là tìm thấy. Tối ưu hóa hàm tìm kiếm phần từ A[j] = Binary Search
->Đpt: (n*logn)

2. Sử dụng 2 con trỏ, con trỏ left bắt đầu tại vị trí đầu mảng, con trỏ right bắt đầu từ vị trí cuối mảng. 
.Nếu A[left] + A[right] = sum -> xuất ra tìm thấy
.Nếu A[left] + A[right] > sum -> giảm sum vế trái = cách giảm vị trí phần tử right -> A[right] = A[right - 1]
.Nếu A[left] + A[right] < sum -> tăng sum vế trái = cách tăng vị trí phần tử left -> A[left] = A[left + 1]

Ta biết cách tăng giảm sum ở vế trái bởi vì đây là mảng tăng dần

*/

#include<iostream>
#include<vector>
#include<fstream>

using namespace std;
typedef long long ll;

void solve(vector<ll> arr, ll n, ll sum){
    ll left = 0;
    ll right = n - 1;
    while(left < right){
        if(arr[left] + arr[right] == sum){
            cout << arr[left] << " & " << arr[right] << endl;
            return;
        }
        else if(arr[left] + arr[right] < sum){
            ++left;
        }
        else{
            --right;
        }
    }
    cout << "Not have pair equal sum" << endl;
    return;
}
int main(){
    ifstream fi;
    fi.open("PairWithGivenSum.txt");
    if(!fi){
        cout << "Cant open this file" << endl;
        return 0;
    }

    ll t; fi >> t;
    while(t--){
        ll n; fi >> n;
        ll sum; fi >> sum;
        vector<ll> arr(n + 1);
        for(ll i = 0;i < n;i++){
            fi >> arr[i];
        }
        solve(arr, n, sum);
    }
}