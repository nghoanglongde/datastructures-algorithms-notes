#include<iostream>
#include<math.h>
#include<vector>
#include<fstream>

using namespace std;

#define ll long long
#define fast_io ios::sync_with_stdio(0), cin.tie(0);
#define vec vector<ll>
#define debug(name) ifstream fi; fi.open(name); if(!fi){cout << "cant open this file" << endl; return 0;}
#define MAXN (ll)(1e8)
#define INF (ll)(1e9)

/*
    Bài toán:
    .Truy vấn update một phần tử và tính tổng phần tử từ a -> b
    
    Idea:
    .Lý thuyết về Segment tree: https://vnoi.info/wiki/algo/data-structures/segment-tree-extend.md
    .Ta có thể tối ưu bộ nhớ xuống còn O(2 * n) như sau: left child = k + 1 và right child = k + 2 * (mid - left + 1)
*/

vec STS;
ll n;

void buildSTSum(vec arr, ll k, ll r_left, ll r_right){
    if(r_left == r_right){
        STS[k] = arr[r_left];
    }
    else{
        ll mid = (r_left + r_right) / 2;
        buildSTSum(arr, 2 * k, r_left, mid);
        buildSTSum(arr, 2 * k + 1, mid + 1, r_right);
        STS[k] += STS[2 * k] + STS[2 * k + 1];
    }
}

void updateSTSum(ll k, ll r_left, ll r_right, ll pos, ll new_val){
    if(r_left == r_right) STS[k] = new_val;
    else{
        ll mid = (r_left + r_right) / 2;
        if(pos <= mid)
            updateSTSum(2 * k, r_left, mid, pos, new_val);
        else
            updateSTSum(2 * k + 1, mid + 1, r_right, pos, new_val);
        STS[k] = STS[2 * k] + STS[2 * k + 1];
    } 
}

ll getSumSTS(ll k, ll r_left, ll r_right, ll q_left, ll q_right){
    if(q_left > q_right) return 0;
    if(r_left == q_left && r_right == q_right) return STS[k];
    ll mid = (r_left + r_right) / 2;
    return getSumSTS(2 * k, r_left, mid, q_left, min(q_right, mid)) + getSumSTS(2 * k + 1, mid + 1, r_right, max(q_left, mid + 1), q_right);
}

int main(){
    fast_io
    debug("SEGT.txt")
    fi >> n;
    vec arr(n);
    STS = vec(4 * n);
    for(ll i = 0;i < n;i++) fi >> arr[i];
    buildSTSum(arr, 1, 0, n - 1);
    ll queries; fi >> queries;
    while(queries--){
        ll opts, a, b; fi >> opts >> a >> b;
        if(opts == 1){
            cout << getSumSTS(1, 0, n - 1, a - 1, b - 1) << endl;
        }
        else{
            updateSTSum(1, 0, n - 1, a - 1, b);
        }
    }
}
