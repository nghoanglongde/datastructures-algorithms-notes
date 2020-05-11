#include<iostream>

using namespace std;
typedef long long ll;

int main(){
    ll n; cin >> n;
    ll sum_e = 0;
    for(int i = 0;i < n - 1;i++){
        ll value; cin >> value;
        sum_e = sum_e + value;
    }
    cout << ((n * (n + 1)) / 2) - sum_e;
}