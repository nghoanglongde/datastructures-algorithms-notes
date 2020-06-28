#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

typedef long long ll;

int main(){
    ifstream fi;
    fi.open("3SUM.txt");
    if(!fi){
        cout << "Cant open this file" << endl;
    }
    ll n, target; fi >> n >> target;
    vector<ll> arr(n);
    for(ll i = 0;i < n;i++){
        fi >> arr[i];
    }
    sort(arr.begin(), arr.end());
    for(ll i = 0;i < n - 2;i++){
        bool flag = false;
        ll sum_two = target - arr[i];
        ll left = i + 1;
        ll right = n - 1;
        while(left <= right){
            ll temp_sum = arr[left] + arr[right];
            if(temp_sum == sum_two){
                flag = true;
                break;
            }
            else if(temp_sum < sum_two){
                ++left;
            }
            else{
                --right;
            }
        }
        if(flag){
            cout << arr[i] << " " << arr[left] << " " << arr[right] << endl;
            return 0;
        }
    }
    cout << "Cant take 3 nums have sum equal target" << endl;
}