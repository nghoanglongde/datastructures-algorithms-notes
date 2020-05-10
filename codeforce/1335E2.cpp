#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;


void solve(int &ans_t, vector<int> v){
    int num = 0, l = 0, r = v.size() - 1, sum = 0;
    for(auto x: v){
        sum += x;
    }
    ans_t = max(sum, ans_t);
    while(1){
        ++num;
        bool c_left = true, c_right = true;
        while(l <= r && c_left){
            if(!v[l]){
                c_left = false;
            }
            else{
                --sum;
            }
            ++l;
        }
        while(l <= r && c_right){
            if(!v[r]){
                c_right = false;
            }
            else{
                --sum;
            }
            --r;
        }
        if(c_left || c_right)
            break;
        ans_t = max(2 * num + sum, ans_t);
    } 
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t; cin >> t;
    vector<int> ans;
    while(t--){
        vector<int> occur[201];
        int n; cin >> n;
        for(int i = 0;i < n;i++){
            int value; cin >> value;
            --value;
            occur[value].push_back(i);
        }
        for(int i = 0;i < 201;i++){
            occur[i].push_back(n);
        }
        int ans_t = 0;
        vector<int> v;
        for(int a = 0;a < 201;a++){
            if(occur[a].size() == 1){
                continue;
            }
            for(int b = 0;b < 201;b++){
                if(a == b){
                    ans_t = max(ans_t, (int)occur[a].size() - 1);
                    continue;
                }
                for(int i = 0, j = 0;i < (occur[a].size() - 1) || j < (occur[b].size() - 1);){
                    if(occur[a][i] < occur[b][j]){
                        v.push_back(0);
                        ++i;
                    }
                    else{
                        v.push_back(1);
                        ++j;
                    }
                }
                solve(ans_t, v);
                v.clear();
            }
        }
        ans.push_back(ans_t);
    }
    for(auto x: ans){
        cout << x << endl;
    }
}