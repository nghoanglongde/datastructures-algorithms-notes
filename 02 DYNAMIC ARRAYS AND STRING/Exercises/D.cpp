//Link problem: https://codeforces.com/problemset/problem/691/A

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
    //debug("D.txt")

    ll n; cin >> n;
    ll sum = 0;
    for(ll i = 0;i < n;++i){
        ll data; cin >> data;
        sum += data;
    }
    if(n == 1){
        if(sum == 1) cout << "YES";
        else cout << "NO";
    }
    else{
        if(n - sum == 1) cout << "YES";
        else cout << "NO";
    }
    

}