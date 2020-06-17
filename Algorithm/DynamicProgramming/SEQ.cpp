//Bài toán tìm dãy con có tổng bằng S các phần tử có thể không liên tiếp
//Bài toán này có liên hệ với bài toán tổ hợp, tính tổng số cách có thể có được để chọn các phần tử có tổng bằng S,
//có thể không liên tiếp ở bài toán Coins


#include<iostream>
#include<vector>
#include<math.h>
#include<fstream>

using namespace std;

typedef long long ll;

ll find(vector<vector<ll>> DP, ll n, ll S){
    ll pos = 0;
    for(ll i = 1;i <= n;++i){
        if(DP[S][i] == 1){
            pos = i;
            break;
        }
    }
    return pos;
}

void DP(vector<ll> arr, ll n, ll S){
    //DP với bảng phương án 2 chiều
    vector<vector<ll>> F(S + 1, vector<ll>(n + 1, 0));
    vector<vector<ll>> DP(S + 1, vector<ll>(n + 1, 0));

    for(ll j = 0;j <= n;j++){
        F[0][j] = 1;
    }

    for(ll k = 1;k <= S;++k){
        for(ll i = 1;i <= n;++i){
            if(k >= arr[i]){
                DP[k][i] = F[k - arr[i]][i - 1];
                //[i - 1] mang ý nghĩa là đã từng có trước đó vị trí [k - arr[i]] hay ko?, chứ ko phải phần tử liền kề phía sau
            }
            else{
                DP[k][i] = 0; //trạng thái tại một vị trí, ban đầu hoặc S < arr[i] thì luôn = 0, khác nhau với bài toán coins chỗ này
                //bài toán coins trạng thái, ban đầu hoặc S < arr[i] thì nó sẽ là kết quả của bài toán trước đó DP[S][i - 1]
            }
            if(DP[k][i] || F[k][i - 1])
                F[k][i] = 1;
            //cout << DP[k][i] << " ";
        }
        //cout << endl;
    }

    //Truy vết
    ll pos = find(DP, n, S);
    if(pos){
        while(pos){
            cout << arr[pos] << " ";
            S = S - arr[pos];
            pos = find(DP, n, S);
        }
        cout << endl;
    }
    else{
        cout << "Cant" << endl;
    }
}

void DP_2(vector<ll> arr, ll n, ll S){
    //DP với bảng cơ sở 1 chiều
    //ĐPT: O(n * m) với n phần tử, và m là tổng của n phần tử
    vector<ll> DP(S + 1);
    DP[0] = 1; DP[S] = 0;
    for(ll i = 1;i <= n;i++){
        for(ll k = S;k >= arr[i];k--){
            if(DP[k] == 0 && DP[k - arr[i]]){
                DP[k] = 1;
            }
        }
    }
    if(DP[S]){
        cout << "Co the tao tong = S" << endl;
    }
    else{
        cout << "Khong the tao tong = S" << endl;
    }
}
int main(){
    ifstream fi;
    fi.open("SEQ.txt");
    if(!fi){
        cout << "can't open this file";
        return 0;
    } 

    ll t; fi >> t;
    while(t--){
        ll n, S;
        fi >> n >> S;
        vector<ll> arr(n + 1,0);
        for(ll i = 1;i <= n;++i){
            ll temp;
            fi >> temp;
            arr[i] = temp;
        }

        DP(arr, n , S);
        //DP_2(arr, n , S);
    }
}