#include<iostream>
#include<math.h>
#include<vector>
#include<fstream>

using namespace std;

#define ll long long
#define fast_io ios::sync_with_stdio(0), cin.tie(0);
#define vec vector<ll>
#define debug(name) ifstream fi; fi.open(name); if(!fi){cout << "cant open this file" << endl; return 0;}

void InsertionSort(vec &arr, ll n){
    for(ll i = 1;i < n;i++){
        ll x = arr[i];
        ll pos = i - 1;
        while(pos >= 0 && arr[pos] > x){
            arr[pos + 1] = arr[pos];
            --pos;
        }
        arr[pos + 1] = x;
    }
}
int main(){
    fast_io
    debug("IS.txt")

    ll n; fi >> n;
    vec arr(n);
    for(ll i = 0;i < n;i++) fi >> arr[i];
    InsertionSort(arr, n);
    for(ll i = 0;i < n;i++) cout << arr[i] << " ";
}