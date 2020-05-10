#include<iostream>
#include<string>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int dem = 0;
        bool tag = true;
        string s;
        int left = 0, right = 0;
        cin >> s;
        for(int i = 0;i < s.length();i++){
            if(s[i] == '1' && tag){
                left = i;
                tag = false;
            }
            else if(s[i] == '1' && i > left){
                right = i;
            }
        }
        for(int i = left + 1;i < right;i++){
            if(s[i] == '0'){
                dem++;
            }
        }
        cout << dem << endl;
    }
}