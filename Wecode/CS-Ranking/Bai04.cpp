#include <iostream>
#include<vector>
#include<map>
using namespace std;

typedef long long ll;

int main(){
    long long n, m;
    cin >> n;
    vector<ll> scores;
    vector<ll> alice;
    vector<ll> count;
    map<ll, int> dup_map;
    for(int i = 0;i < n;i++){
        ll value; cin >> value;
        scores.push_back(value);
    }
    for(int i=0; i < n;i++)
    {
        //hash map để tìm scores bị trùng
        if(dup_map.find(scores[i]) != dup_map.end())
        {
            dup_map[scores[i]]++;
        }
        else{
            dup_map.insert(pair<ll,int>(scores[i],1));
        }
    }
    int size = dup_map.size();
    cin >> m;
    for(int i = 0;i < m;i++){
        ll value; cin >> value;
        alice.push_back(value);
    }
    for(int i = 0;i < m;i++){
        long long k = alice[i];
        for(map<ll, int>::iterator temp = dup_map.begin(); temp != dup_map.end();temp++){
            ll value = temp->first;
            if(value <= k){
                count.push_back(value);
            }
            else{
                if(count.empty()){
                    cout << size + 1 << endl;
                }
                else{
                    cout << size - count.size() + 1 << endl;
                }
                count.clear();
                break;
            }
        }
        if(!count.empty()){
            cout << 1 << endl;
            count.clear();
        }
    }
}