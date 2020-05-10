#include<iostream>
#include<fstream>
using namespace std;

int main(){
    //dữ liệu đặt trong file input.txt rồi đọc file ra
    ifstream fi;
    fi.open("input.txt");
    if(!fi){
        cout << "can't open this file";
        return 0;
    } 

    string S, result;
    cin >> S;
    result = (S[0] == S[1] && S[0] == S[2]) ? "No" : "Yes";
    cout << result;
}