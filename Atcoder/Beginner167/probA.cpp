#include<iostream>
using namespace std;
 
int main(){
	string s; cin >> s;
  	string t; cin >> t;
  	int dem = 0;
  	for(int i = 0;i < s.length();i++){
    	if(s[i] != t[i]){
        	++dem;
        }
    }
    if(dem >= 1){
        cout << "No";
    }
    else{
        cout << "Yes";
    }
}