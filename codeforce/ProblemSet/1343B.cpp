#include<iostream>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        long long n; cin >> n;
        long long sum = 1;
        if((n / 2) % 2 != 0){
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
            int even_val = 2;
            long long sum = 0;
            for(int i = 1;i <= n/2;i++){
                sum = sum + even_val;
                cout << even_val << " ";
                even_val = even_val + 2;
            }
            int odd_val = 1;
            for(int i = 1;i <= n/2;i++){
                if(i == n/2){
                    cout << sum << endl;
                    break;
                }
                sum = sum - odd_val;
                cout << odd_val << " ";
                odd_val = odd_val + 2;
            }
        }
    }
}