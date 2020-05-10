//Dãy con dài nhất có tổng chia hết cho K, không cần liên tục

//Xem ví dụ trong sách thầy hoàng
#include<iostream>
#include<vector>
#define INF 1000000;
using namespace std;
int main(){
    int n, k;
    int sum = 0;
    cin >> n >> k;
    vector<int> arr(n + 1, 0);
    vector<vector<int>> DP(n + 1,vector<int>(k + 1,0));
    for(int i = 1;i <= n;i++){
        int temp;
        cin >> temp;
        arr[i] = temp;
        sum = (sum + arr[i]) % k;
    }
    cout << sum << endl;
    DP[0][0] = 0;
    cout << DP[0][0] << " ";
    for(int i = 1;i < k;i++){
        DP[0][i] = INF;
        cout << DP[0][i] << " ";
    }
    cout << endl;
    for(int i = 1;i <= n;i++){
        for(int t = 0;t < k;t++){
            DP[i][t] = min(DP[i - 1][t], DP[i - 1][((t - arr[i]) % k + k) % k] + 1);
            cout << DP[i][t] << " ";
        }
        cout << endl;
    }
    cout << n - DP[n][sum % k];
    return 0;
}