#include<iostream>
#include<vector>
#include<math.h>
#include<fstream>

using namespace std;

#define ll long long

/*
    Bài toán 1:
    Cho dãy số A có N phần tử, giá trị ban đầu của các phần tử bằng 0. Có 2 loại truy vấn cần thực hiện:
    .Update A(i)
    .Tính tổng của mảng từ A(1) đến A(i) hoặc từ A(a) đến A(b) tùy theo loại truy vấn

    Bài toán 2:
    Cho dãy số A có N phần tử, giá trị ban đầu của các phần tử bằng 0. Có 2 loại truy vấn cần thực hiện:
    .Update A(i)
    .Tìm phần tử nhỏ nhất từ A(1) đến A(i)

    Idea: Sử dụng cây Fenwick Tree hay còn gọi là cây Binary Indexed Tree(BIT) ta có thể update các truy vấn
    trong thời gian O(logn), tính tổng trong thời gian O(logn) và tìm phần tử nhỏ nhất trong thời gian O(logn)

    Cách xây dựng cây BIT trên mảng
    Xem BIT như một mảng F có N phần tử, đánh số từ 1. F(i) lưu tổng của i & (-i) phần tử, bắt đầu từ A(i) ngược về A(1)
    Tức là F(i) lưu tổng từ A(i-(i&-i)+1) đến A(i).
*/
class FenWickTreeSum{
    private:
        ll n;
        vector<ll> BIT;
    public:
        FenWickTreeSum(){
            this->n = 0;
            this->BIT.assign(n, 0);
        }
        FenWickTreeSum(vector<ll> arr){
            this->n = arr.size() - 1;
            this->BIT.assign(this->n + 1, 0);
            for(ll i = 1;i <= this->n;i++){
                update(i, arr[i]);
            }
        }
        void update(ll x, ll val){
            while(x <= this->n){
                this->BIT[x] = this->BIT[x] + val;
                x = x + (x & -x);
            }
        }

        ll sum(ll k){
            //tổng từ A[1] -> A[k]
            ll sum = 0;
            while(k >= 1){
                sum = sum + this->BIT[k];
                k = k - (k & -k);
            }
            return sum;
        }

        ll sum(ll a, ll b){
            //tổng từ A[a] -> A[b]
            return sum(b) - sum(a - 1);
        }
};
class FenWickTreeMin{
    private:
        ll n;
        vector<ll> BIT;
        const ll INF = (ll)1e9;
    public:
        FenWickTreeMin(){
            this->n = 0;
            this->BIT.assign(n, INF);
        }
        FenWickTreeMin(vector<ll> arr){
            this->n = arr.size() - 1;
            this->BIT.assign(this->n + 1, INF);
            for(ll i = 1;i <= this->n;i++){
                update(i, arr[i]);
            }
        }
        void update(ll x, ll val){
            while(x <= this->n){
                this->BIT[x] = min(this->BIT[x], val);
                x = x + (x & -x);
            }
        }

        ll getMin(ll k){
            //phần tử nhỏ nhất từ A[1] -> A[k]
            ll ans = INF;
            while(k >= 1){
                ans = min(this->BIT[k], ans);
                k = k - (k & -k);
            }
            return ans;
        }

};

int main(){
    ifstream fi;
    fi.open("BIT.txt");
    if(!fi){
        cout << "cant open this file" << endl;
        return 0;
    }

    //Bài toán 1
    ll n, queries; fi >> n >> queries;
    vector<ll> arr(n + 1);
    for(ll i = 1;i <= n;i++){
        fi >> arr[i];
    }
    FenWickTreeSum tree_sum(arr);
    while(queries--){
        ll opts; fi >> opts;
        if(opts == 1){
            ll k; fi >> k;
            cout << tree_sum.sum(k) << endl;
        }
        else if(opts == 2){
            ll a, b; fi >> a >> b;
            cout << tree_sum.sum(a, b) << endl;
        }
        else{
            ll pos, val_update; fi >> pos >> val_update;
            tree_sum.update(pos, val_update);
        }
    }

    //Bài toán 2
    FenWickTreeMin tree_min(arr);
    ll queries_min; fi >> queries_min;
    while(queries_min--){
        ll opts_min; fi >> opts_min;
        if(opts_min == 1){
            ll k; fi >> k;
            cout << tree_min.getMin(k) << endl;
        }
        else{
            ll pos_up, val_up; fi >> pos_up >> val_up;
            tree_min.update(pos_up, val_up);
        }
    }
}