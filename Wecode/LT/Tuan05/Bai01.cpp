/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
template
###End banned keyword*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

//###INSERT CODE HERE -

typedef long long ll;

int main(){
    ll n, t; cin >> n >> t;
    ll *arr = new ll[n];
    for(ll i = 0;i < n;i++){
        cin >> arr[i];
    }
    while(t--){
        ll k; cin >> k;
        ll left = 0;
        ll right = n - 1;
        ll mid = (left + right) / 2;
        while(left != mid && right != mid){
            if(arr[mid] < k){
                left = mid;
            }
            else{
                right = mid;
            }
            mid = (left + right) / 2;
        }
        bool flag = false;
        ll pos;
        for(pos = left;pos <= right;pos++){
            if(arr[pos] >= k){
                flag = true;
                break;
            }
        }
        if(flag){
            cout << n - pos << endl;
        }
        else{
            cout << 0 << endl;
        }    
    }
}