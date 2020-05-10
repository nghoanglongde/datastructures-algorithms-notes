#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    for(int i = 1;i <= n;i++){
        int temp;
        cin >> temp;
        if(temp % 2 == 0){
            if(temp % 3 != 0 && temp % 5 != 0){
                cout << "DENIED";
                return 0;
            }
        }
    }
    cout << "APPROVED";
}