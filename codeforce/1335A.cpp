#include<iostream>
#include<vector>
using namespace std;
int main(){
    vector<int> ans;
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        int ans_t;
        if(n == 1 || n == 2){
            ans_t = 0;
        }
        else{
            if(n % 2 == 0){
                ans_t = n/2 - 1;
            }
            else{
                ans_t = n/2;
            }
        }
        ans.push_back(ans_t);
    }
    for(auto x: ans){
        cout << x << endl;
    }
}