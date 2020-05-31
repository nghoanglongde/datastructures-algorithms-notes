/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
#include <string>
using namespace std;

//###INSERT CODE HERE -

bool check(string str) { 
    int *map = new int[str.length() + 1];
    for(int i = 0;i < str.length();i++){
        map[i] = 0;
    }
    int max_dup = 0; 
    for (int j = 0; j < (str.length()); j++) { 
        map[(int)str[j] - 'a']++; 
        if (map[(int)str[j] - 'a'] > max_dup) 
            max_dup = map[(int)str[j] - 'a']; 
    } 
  
    if (max_dup > (str.length() - max_dup + 1)) //nếu số phần tử chuỗi trùng dài nhất > số phần tử còn lại của chuỗi + 1 -> ko thể sắp phù hợp y/c
        return false; 
    return true; 
} 
int main(){
    string s;
    cin >> s;
    if(check(s)){
        cout << "POSSIBLE";
    }
    else{
        cout << "IMPOSSIBLE";
    }
}