#include<iostream>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        long long n; cin >> n;
        long long x, sum = 1;
        for(long long i = 2;i <= n;i = i * 2){
            sum = sum + i;
            if(n % sum == 0){
                x = n / sum;
                break;
            }
        }
        cout << x << endl;
    }
}