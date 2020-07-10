#include<iostream>
#include<math.h>
#include<vector>
#include<fstream>

using namespace std;

#define ll long long
#define fast_io ios::sync_with_stdio(0), cin.tie(0);
#define vec vector<ll>
#define debug(name) ifstream fi; fi.open(name); if(!fi){cout << "cant open this file" << endl; return 0;}

void SelectionSort(vec &arr, ll n){
    for(ll i = 0;i < n - 1;i++){
        ll min = i;
        for(ll j = i + 1;j < n;j++){
            if(arr[i] > arr[j]){
                min = j;
            }
        }
        if(min != i){
            swap(arr[min], arr[i]);
        }
    }
}
int main(){
    fast_io
    debug("SS.txt")

    ll n; fi >> n;
    vec arr(n);
    for(ll i = 0;i < n;i++) fi >> arr[i];
    SelectionSort(arr, n);
    for(ll i = 0;i < n;i++) cout << arr[i] << " ";
}