#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

#define ll long long

/*
    Bài toán:
    Cho dãy số A có N phần tử, giá trị ban đầu của các phần tử bằng 0. Có 2 loại truy vấn cần thực hiện:
    .Tăng A(i) lên một đơn vị
    .Tính tổng của mảng từ A(1) đến A(i)

    Idea: Sử dụng cây Fenwick Tree hay còn gọi là cây Binary Indexed Tree(BIT) ta có thể update các truy vấn
    trong thời gian O(logn) và tính tổng trong thời gian O(logn)

    Cách xây dựng cây BIT trên mảng
    Xem BIT như một mảng F có N phần tử, đánh số từ 1. F(i) lưu tổng của i & (-i) phần tử, bắt đầu từ A(i) ngược về A(1)
    Tức là F(i) lưu tổng từ A(i-(i&-i)+1) đến A(i).
*/

void update(ll x, ll n, ll val, vector<ll> &BIT){
    while(x <= n){
        BIT[x] = BIT[x] + val;
        x = x + (x & -x);
    }
}

ll sum(ll k, vector<ll> BIT){
    //tổng từ A[1] -> A[k]
    ll sum = 0;
    while(k >= 1){
        sum = sum + BIT[k];
        k = k - (k & -k);
    }
    return sum;
}

ll sum(ll a, ll b, vector<ll> BIT){
    //tổng từ A[b] -> A[a]
    return sum(b, BIT) - sum(a, BIT);
}

int main(){
    ifstream fi;
    fi.open("BIT.txt");
    if(!fi){
        cout << "cant open this file" << endl;
        return 0;
    }

    ll n; fi >> n;
    vector<ll> arr(n + 1);
    vector<ll> BIT(n + 1, 0);
    for(ll i = 1;i <= n;i++){
        fi >> arr[i];
        update(i, n, arr[i], BIT);
    }
    cout << sum(6, BIT) << endl;
    cout << sum(4, 7, BIT) << endl;
}