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
ll Query(vector<ll> arr, vector<ll> block ,ll a, ll b){
}
int main(){
    ifstream fi;
    fi.open("MinimumQueries.txt");
    if(!fi){
        cout << "cant open this file" << endl;
        return 0;
    }
    ll n; fi >> n;
    vector<ll> arr(n);
    vector<ll> block(ceil(sqrt(n)));
    for(ll i = 0;i < n;i++) fi >> arr[i];
    //Preprocess(arr, block, n);
    
    ll queries; fi >> queries;
    while(queries--){
        ll a, b; fi >> a >> b;
        ll ans = Query(arr, block ,a, b);
        cout << ans << endl;
    }
}