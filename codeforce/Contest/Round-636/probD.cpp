#include <bits/stdc++.h>

using namespace std;
	
int main(){
    int t; cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> arr;
        for(int i = 0;i < n;i++){
            int data; cin >> data;
            arr.push_back(data);
        }
        vector<int> zero_change(2 * k + 1);
        for(int i = 0;i < n/2;i++){
            ++zero_change[arr[i] + arr[n - i - 1]];
        }
        vector<int> one_change(2 * k + 2);
        for(int i = 0;i < n/2;++i){
            int l1 = 1 + arr[i], l2 = 1 + arr[n - i - 1];
            int r1 = arr[i] + k + 1, r2 = arr[n - i - 1] + k + 1; //giới hạn sum của 1 cặp số nằm trong khoảng min(l1, l2) + 1 <= sum < max(r1, r2) + k + 1 
            ++one_change[min(l1, l2)]; //chuẩn bị dữ liệu cho prefix sum one_change
            --one_change[max(r1, r2)];
        }
        int ans = (int)1e8;
        for(int i = 1;i <= 2*k + 1;i++){
            one_change[i] = one_change[i] + one_change[i - 1];
        }
        for(int i = 2;i <= 2*k;i++){
            ans = min(ans, (one_change[i] - zero_change[i]) + (n - one_change[i] * 2));
        }
        cout << ans << endl;
    }
}
