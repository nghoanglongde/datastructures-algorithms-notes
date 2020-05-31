/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
class
struct
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
        for(pos = left;pos <= right;++pos){
            if(arr[pos] == k){
                flag = true;
                break;
            }
        }
        if(flag){
            ll n_left = pos;
            ll n_right = n - 1;
            ll n_mid = (n_left + n_right) / 2;
            while(n_left != n_mid && n_right != n_mid){
                if(arr[n_mid] <= k){
                    n_left = n_mid;
                }
                else{
                    n_right = n_mid;
                }
                n_mid = (n_left + n_right) / 2;
            }
            ll n_pos;
            for(n_pos = n_right;n_pos >= n_left;--n_pos){
                if(arr[n_pos] == k){
                    break;
                }
            }
            cout << n_pos - pos + 1 << " " << pos + 1 << " " << n_pos + 1 << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
}