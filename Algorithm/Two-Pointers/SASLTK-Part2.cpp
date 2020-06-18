/*
    Bài toán: Cho một mảng n phần tử, đếm số mảng con có các phần tử liên tiếp có tổng nhỏ hơn hoặc bằng k

    Idea:
    B1: Sử dụng 2 con trỏ, sử dụng con trỏ end trượt ngang theo các phần tử mảng để cộng dồn vào một biến sum
    B2: Trường hợp sum > target ta giảm sum xuống sao cho <= target bằng cách cho con trỏ start trượt ngang từ bên trái qua rồi trừ dần đi
    B3: cập nhật lại ans

    Đpt: O(n)

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
               //tránh trường hợp 10 8 5 với target = 6 thì khi giảm sum thì start sẽ vượt qua end
               sum = sum - arr[start];
               ++start;
            }
            if(sum <= target)
                ans = ans + (end - start + 1);
                //end - start + 1 vì: ví dụ 8 1 2 5 7 | 8 thì giả dụ end = 3 và start = 1 -> end - start + 1 = 3(trường hợp 2, 5 và 1 + 2 + 5) ko có
                //trường hơp 1 là do tại vị trí end = 1 nó đã cộng trường hợp 1 <= target vào ans rồi.
            ++end;
        }
        cout << ans << endl;
    }
}