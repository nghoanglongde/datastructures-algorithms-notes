#include<bits/stdc++.h>

using namespace std;

int main(){
	string s, aux = "";
	cin >> s;
	int contU = 0;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == '1')
            contU++;
		else 
            aux += s[i];
	}
	string u(contU, '1');
	for(int i = 0; i < aux.size(); i++){
		if(u == ""){
			cout << aux[i];
			continue;
		}
		if(aux[i] == '2'){
			cout << u << '2';
			u = "";
		}
        else{ 
            cout << aux[i];
        }
	}
	if(u != "")
        cout << u;
	return 0;
}