/*
    Đề bài: Cho một mảng các phần tử (>= 0) và một target sum, tìm một subarray có sum = target, output index các phần tử

    Example: 9 3 2 5 1 1 2 3 | target = 8 
    Ouput: 2 3 4

    Idea: Xem lại bài Sub Array Sum Less Than K là hiểu
*/
#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

typedef long long ll;

int main(){
    ifstream fi;
    fi.open("SubArraySum.txt");
    if(!fi){
        cout << "Cant open this file";
        return 0;
    }
    ll t; fi >> t;
    while(t--){
        ll n, target; fi >> n >> target;
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++){
            cin >> arr[i];
        }
        ll start = 0, end = 0, sum = 0;
        bool tag = false;
        while(end < n){
            sum = sum + arr[end];
            while(start < end && sum > target){
                sum = sum - arr[start];
                ++start;
            }
            if(sum == target){
                tag = true;
                break;
            }
            ++end;
        }
        if(tag){
            for(ll pos = start;pos <= end;++pos){
                cout << pos << " ";
            } 
            cout << endl;
        }
        else{
            cout << "-1" << endl;
        }
    }
}