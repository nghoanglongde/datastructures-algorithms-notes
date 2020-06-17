/*
    Bài toán: Cho một mảng n phần tử, đếm số mảng con có các phần tử liên tiếp có tổng lớn hơn hoặc bằng k

    Idea:
    Với mỗi chỉ số end, ta tìm chỉ số start lớn nhất sao cho a[start] + a[start+1]+ … + a[end] >=S. Như thế sẽ có start + 1 chuỗi con 
    thỏa mãn điều kiện có chỉ số cuối là end. Các dãy đó là: 
    {a0, a1, .., a[end]}, { a1,a2 .., a[end]}, {a[start], a[start+1], .., a[end]}. Vì thế ta cộng dồn vào kết quả một lượng start + 1

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
            while(start < end && sum - arr[start] >= target){
               sum = sum - arr[start];
               ++start;
            }
            if(sum >= target)
                ans = ans + (start + 1);
            ++end;
        }
        cout << ans << endl;
    }
}