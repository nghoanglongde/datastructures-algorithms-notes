//Link problem: https://codeforces.com/problemset/problem/242/B

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
    //debug("C.txt")

    ll n; cin >> n;
    map<pair<ll, ll>, ll> my_map;
    ll minx = INF, maxy = -INF;
    for(ll i = 1;i <= n;i++){
        ll start, end; cin >> start >> end;
        my_map.insert(make_pair(make_pair(start, end), i));
        minx = min(minx, start);
        maxy = max(maxy, end);
    }
    auto temp = my_map.find(make_pair(minx, maxy));
    if(temp != my_map.end()) cout << temp->second;
    else cout << -1;
}