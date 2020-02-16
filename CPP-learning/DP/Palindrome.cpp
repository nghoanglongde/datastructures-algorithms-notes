#include<iostream>
#include<string>
#include<math.h>
#define maxN 1000

bool arr_s[maxN][maxN];
int max_pal = -1*maxN;
using namespace std;

//time complexity: 0(n^2)
void DP(string s){
    int pos_right;
    int pos_first;
    int pos_end;
    for(int i = 0;i < s.length();++i){
        arr_s[i][i] = true;
    }
    for(int num = 2;num <= s.length();num++){
        for(int i = 0;i <= s.length() - num;++i){
            pos_right = i + (num - 1);
            if(s[i] == s[pos_right]){
                if(num == 2){
                    arr_s[i][pos_right] = true;
                }
                else if(num > 2){
                    arr_s[i][pos_right] = arr_s[i + 1][pos_right - 1];
                }
                if(arr_s[i][pos_right] && (abs(i - pos_right) + 1) > max_pal){
                    max_pal = i - pos_right + 1;
                    pos_first = i;
                    pos_end = pos_right;
                }
            }
            else{
                arr_s[i][pos_right] = false;
            }
        }
    }
    for(int i = pos_first;i <= pos_end;i++){
        cout << s[i];
    }
}

int main(){
    string s;
    cin >> s;
    DP(s);
}