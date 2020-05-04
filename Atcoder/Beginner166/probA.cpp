#include<iostream>
#include<string>
using namespace std;

int main(){
    string s; cin >> s;
    string result = (s == "ABC") ? "ARC" : "ABC";
    cout << result;
    return 0;
}