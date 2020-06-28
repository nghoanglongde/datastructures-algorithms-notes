#include<iostream>
#include<vector>
#include<algorithm>
#include<deque>
#include<fstream>
using namespace std;

typedef long long ll;

int main(){
    ifstream fi;
    fi.open("SlidingWinMin.txt");
    if(!fi){
        cout << "Cant open this file" << endl;
        return 0;
    }
    deque<int> dq;
    ll n, k; fi >> n >> k;
    vector<ll> arr(n);
    for(ll i = 0;i < n;++i){
        fi >> arr[i];
    }
    ll i;
    for(i = 0;i < k;++i){
        while(!dq.empty() && arr[i] >= arr[dq.back()]){
            dq.pop_back();
        }
        dq.push_back(i);
    }
    for(;i < n;i++){
        cout << arr[dq.front()] << " ";
        while(!dq.empty() && arr[i] >= arr[dq.back()]){
            dq.pop_back();
        }
         while(dq.front() <= i - k){
            dq.pop_front();
        }
        dq.push_back(i);
    }
    if(!dq.empty()){
        cout << arr[dq.front()];
        dq.clear();
    }
}