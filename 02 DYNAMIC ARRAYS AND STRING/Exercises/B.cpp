//Link problem: https://codeforces.com/problemset/problem/673/A

#include<iostream>
#include<math.h>
#include<vector>
#include<map>
#include<unordered_map>
#include<fstream>
#include<string.h>
#include<algorithm>

#define ll long long
#define fast_io ios::sync_with_stdio(0), cin.tie(0);
#define debug(name) ifstream fi; fi.open(name); if(!fi){cout << "cant open this file" << endl; return 0;}
#define MAXN (ll)(1e8)
#define INF (ll)(1e9)
#define vec vector<ll>
#define mp map<ll, ll>
#define un_mp unordered_map<ll, ll>

using namespace std;

int main(){
    //fast_io
    //debug("B.txt")

    ll n; cin >> n;
    vec arr(n + 1, 0);
    ll ans = 0;
    bool tag = false;
    for(ll i = 1;i <= n;i++) cin >> arr[i];
    for(ll i = 1;i <= n;i++){
        if(arr[i] - arr[i - 1] > 15){
            tag = true;
            ans = arr[i - 1];
            break;
        }
    }
    if(tag){
        cout << ans + 15;
    }
    else if(90 - arr.back() > 15){
        cout << arr.back() + 15;
    }
    else{
        cout << 90;
    }
}