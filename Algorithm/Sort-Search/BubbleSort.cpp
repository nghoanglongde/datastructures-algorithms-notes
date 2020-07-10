#include<iostream>
#include<math.h>
#include<vector>
#include<fstream>

using namespace std;

#define ll long long
#define fast_io ios::sync_with_stdio(0), cin.tie(0);
#define vec vector<ll>
#define debug(name) ifstream fi; fi.open(name); if(!fi){cout << "cant open this file" << endl; return 0;}

/*
    Idea: 
    .So sánh 2 phần tử liền kề nhau, lặp lại liên tục trên 1 mảng để đưa mảng về mảng tăng dần
    .Qua mỗi vòng lặp thì đã có i phần tử cuối cùng đã được sắp xếp nên ta chỉ cần sắp xếp đến n - i + 1
    .Nếu không có phần tử nào cần swap nữa tức đã ắp xếp đủ -> break
*/

void BubbleSort(vec &arr, ll n){
    for(ll i = 0;i < n - 1;i++){
        bool haveswap = false;
        for(ll j = 0;j < n - i + 1;j++){
            if(arr[j] > arr[j + 1]){
                swap(arr[j], arr[j + 1]);
                haveswap = true;
            }
        }
        if(!haveswap) break;
    }
}
int main(){
    fast_io
    debug("BBS.txt")

    ll n; fi >> n;
    vec arr(n);
    for(ll i = 0;i < n;i++) fi >> arr[i];
    BubbleSort(arr, n);
    for(ll i = 0;i < n;i++) cout << arr[i] << " ";
}