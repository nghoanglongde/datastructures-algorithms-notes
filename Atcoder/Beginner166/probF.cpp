//Lưu ý trường hợp A = 1, B = 1, C = 0 mà AB, BC thì ta phải chọn tăng B chứ ko phải tăng A
#include<iostream>
#include<map>
#include<vector>

using namespace std;
typedef long long ll;

int main(){
    ll n, a, b, c;
    cin >> n >> a >> b >> c;
    map<char, ll> data;
    data['A'] = a;
    data['B'] = b;
    data['C'] = c;
    vector<char> move;
    string choices[n];
    for(int i = 0;i < n;i++){
        cin >> choices[i];
    }
    for(int i = 0;i <= n - 1;i++){
        char ch_1 = choices[i][0];
        char ch_2 = choices[i][1];
        if(data[ch_1] > data[ch_2]){
            data[ch_1] -= 1;
            data[ch_2] += 1;
            move.push_back(ch_2);
        }
        else if(data[ch_1] < data[ch_2]){
            data[ch_2] -= 1;
            data[ch_1] += 1;
            move.push_back(ch_1);
        }
        else{
            if((i < n - 1) && (ch_1 == choices[i + 1][0] || ch_1 == choices[i + 1][1])){
                data[ch_1] += 1;
                data[ch_2] -= 1;
                move.push_back(ch_1);
            }
            else{
                data[ch_1] -= 1;
                data[ch_2] += 1;
                move.push_back(ch_2);
            }
        }
        if(data['A'] < 0 || data['B'] < 0 || data['C'] < 0){
            cout << "No" << endl;
            return 0;
        }
    }
    if(data['A'] < 0 || data['B'] < 0 || data['C'] < 0){
        cout << "No" << endl;
        return 0;
    }
    cout<< "Yes" << endl;
    for(auto x: move){
        cout << x << endl;
    }
    return 0;
}











