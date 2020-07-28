//Link problem: https://codeforces.com/problemset/problem/572/A

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
    fast_io
    //debug("A.txt")

    ll na, nb; cin >> na >> nb;
    ll k, m; cin >> k >> m;
    vec arrA(na);
    vec arrB(nb);
    for(ll i = 0;i < na;++i) cin >> arrA[i];
    for(ll i = 0;i < nb;++i) cin >> arrB[i];
    if(arrA[k - 1] < arrB[nb - m]){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}