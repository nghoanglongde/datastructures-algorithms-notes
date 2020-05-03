//Ta có thể thấy với số 1 nó có thể đổi chỗ với bất cứ số nào, nên ý tưởng là tách số 1 ra khỏi chuỗi gốc, để tạo ra 1 dãy nhỏ nhất
//ta chỉ cần thêm dãy các số 1 đã được tách ra trước số 2, vì nếu thêm sau số 2 nó sẽ là 2xxx > 1xxx, nếu trong chuỗi ko có số
//2 nào, ta sẽ thêm nó vào cuối chuỗi là ta đã đc 1 chuỗi nhỏ nhất

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