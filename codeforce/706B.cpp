#include<algorithm>
#include<iostream>
#include<vector>
using namespace std; 

int main(){
    int n; cin >> n;
    vector<int> cities;
    vector<int> queries;
    for(int i = 0;i < n;++i){
        int value; cin >> value;
        cities.push_back(value);
    }
    sort(cities.begin(), cities.end());
    int q; cin >> q;
    for(int i = 0;i < q;++i){
        int query; cin >> query;
        queries.push_back(query);
    }
    for(int i = 0;i < q;i++){
        if(queries[i] < cities[0]){
            cout << 0 << endl;
        }
        else{
            auto k = upper_bound(cities.begin(), cities.end(), queries[i]) - cities.begin();
            cout << k << endl;
        }
    }

}