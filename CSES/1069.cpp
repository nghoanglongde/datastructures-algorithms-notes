#include<iostream>
#include<string>

using namespace std;
typedef long long ll;

int main(){
    string s; cin >> s;
    ll ans = 1;
    ll count = 1;
    for(int i = 1;i < s.length();++i){
        if(s[i] == s[i - 1]){
            ++count;
            ans = max(ans, count);
        }
        else{
            count = 1;
        }
    }
    cout << ans;
}