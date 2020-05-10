#include<iostream>
#include<map>
#include<vector>
using namespace std;
int main(){
    int max = 0;
    long long int n;
    vector<string> result;
    map<string,int> table;
    cin >> n;
    vector<string> text;
    for(int i = 1;i <= n;i++){
        string temp;
        cin >> temp;
        table[temp] += 1;
    }
    map<string,int>::iterator i;
    for(i = table.begin();i != table.end();i++){
        max = (max < i->second) ? i->second : max;
    }
    for(i = table.begin();i != table.end();i++){
        if(i->second == max){
            cout << i->first << endl;
        }
    }
    return 0;
}