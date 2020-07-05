#include<iostream>
#include<math.h>
#include<vector>
#include<fstream>

using namespace std;

typedef long long ll;
/*
    Bài toán: Cho mảng A[0, N−1]. Với Q truy vấn. Mỗi truy vấn gồm 2 số a, b và bạn cần đưa ra phần tử có giá trị nhỏ nhất 
    trong đoạn từ a đến b của mảng A, ký hiệu là RMQA(a, b).

    Idea: Mình sẽ sử dụng Sparse Table
*/
int main(){
    ifstream fi;
    fi.open("RMQ.txt");
    if(!fi){
        cout << "cant open this file" << endl;
        return 0;
    }
    ll n; fi >> n;
    vector<ll> arr(n);
    vector<vector<ll>> M(n, vector<ll>(32, n));
    for(ll i = 0;i < n;i++){ 
        fi >> arr[i];
        M[i][0] = arr[i];
    }

    for(ll k = 1;(1 << k) <= n;k++){
        for(ll i = 0;i + (1 << k) - 1 < n;i++){
            M[i][k] = min(M[i][k - 1], M[i + (1 << (k - 1))][k - 1]);
        }
    }
    
    ll queries; fi >> queries;
    while(queries--){
        ll a, b; fi >> a >> b;
        a = a - 1, b = b - 1;
        ll k = log2(b - a + 1);
        cout << min(M[a][k], M[b - (1 << k) + 1][k]) << endl;
    }
}
