#include<iostream>
#include<fstream>
#include<vector>
using namespace std;

typedef long long ll;

void solve(vector<ll> arr, ll S){
    //giá trị tối ưu nhất để chia ra 2 phần kẹo bằng nhau: S = T/2 với T là tổng số kẹo của mỗi phần tử arr[i], nếu ko thể tạo ra tổng = T/2
    //thì ta chọn S lần lượt <= T/2
    //độ chêch lệch nhỏ nhất giữa 2 phần: T - 2S
    //Idea: ta chọn giá trị tối ưu nhất là S/2, nếu không thể tạo ra tổng = S/2 thì ta giảm S xuống dần dần
    //2 phần kẹo sẽ là Part_1 = part_sum và Part_2 = S - part_sum
    ll original_sum = S;
    ll part_sum = S / 2;
    while(true){
        vector<ll> DP(part_sum + 1);
        DP[0] = 1; DP[part_sum] = 0;
        for(ll i = 0;i < arr.size();i++){
            for(ll k = part_sum;k >= arr[i];k--){
                if(DP[k] == 0 && DP[k - arr[i]]){
                    DP[k] = 1;
                }
            }
        }
        if(DP[part_sum]){
            cout << part_sum << " " << original_sum - part_sum << endl;
            break;
        }
        else{
            part_sum = part_sum - 1;
        }
    }
}

int main(){
    ifstream fi;
    fi.open("CK.txt");
    if(!fi){
        cout << "Cant open this file" << endl;
        return 0;
    }

    ll t; fi >> t;
    while(t--){
        ll n; fi >> n;
        ll S = 0;
        vector<ll> arr(n);
        for(ll i = 0;i < n;i++){
            fi >> arr[i];
            S = S + arr[i];
        } 
        solve(arr, S);
    }
}