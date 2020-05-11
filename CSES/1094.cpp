#include<iostream>
#include<vector>

using namespace std;
typedef long long ll;

int main(){
    ll n; cin >> n;
    vector<ll> arr;
    ll ans = 0;
    for(int i = 0;i < n;i++){
        ll value; cin >> value;
        arr.push_back(value);
    }
    for(int i = 1; i < n;++i){
        if(arr[i] < arr[i - 1]){
            ans = ans + (arr[i - 1] - arr[i]);
            arr[i] = arr[i] + (arr[i - 1] - arr[i]);
        }
    }
    cout << ans;
}