#include<iostream>
#include<string>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long int x,y,a,b;
        long long int s,v;
        cin >> x >> y >> a >> b;
        s = x - y;
        v = -1*(a + b);
        if(s % v == 0){
            cout << s/v << endl;
        }
        else
            cout << -1 << endl;
    }
    return 0;
}