#include<iostream>

using namespace std;
typedef long long ll;

int main(){
    ll a, b, c, k;
    cin >> a >> b >> c >> k;
    ll ans = a;
    if(k > a){
        k = k - a;
        k = k - b;
        if(k > 0){
            cout << ans - k;
        }
        else{
            cout << ans;
        }
    }
    else{
        cout << k;
    }
}