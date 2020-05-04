#include<iostream>
#include<map>

using namespace std; 
typedef long long ll; 
bool present(map<int, int> mp, int x){
    if(mp.find(x) != mp.end()){
        return true;
    }
    return (mp.find(x) != mp.end()) ? true : false;
}
int main()
{
    //ta có nhận xét như sau : |j - i| = a[i] + a[j] với j > i -> j - a[j] = a[i] + i
    int n, ans = 0;
    cin >> n;
    map<int, int> mp;
    for(int i = 1;i <= n;++i){
        int x;
        cin >> x;
        ans = ans + mp[i - x];
        mp[i + x]++;
    }
 
    cout << ans;
 
    return 0;
}
 