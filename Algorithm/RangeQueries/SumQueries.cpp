#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

typedef long long ll;

/*
    Idea: 
    .Nếu ta dùng cách thông thường, với mỗi query sum[a, b], đpt memory: 0(1), đpt time: 0(n) vì phải duyệt mảng từ [a, b]
    .Còn nếu dùng prefixsum, ta sẽ hi sinh memory là 0(n) để tạo ra một mảng pref nhưng đổi lại với mỗi query sum[a, b] ta chỉ cần O(1)

*/
int main(){
    fstream fi;
    fi.open("SumQueries.txt");
    if(!fi){
        cout << "cant open this file" << endl;
        return 0;
    }
    ll n; fi >> n;
    vector<ll> arr(n);

    vector<ll> pref(n);
    for(ll i = 0;i < n;i++){
        //nhập dữ liệu vào mảng, chuẩn bị một mảng prefixsum
        fi >> arr[i];
        if(i == 0)  pref[i] = arr[i];
        else{
            pref[i] = pref[i - 1] + arr[i];
        }
    }    

    //Truy vấn sum[a, b] = sum[0, b] - sum[0, a - 1]; trường hợp a = 0 -> ta khởi tạo sẵn sum[0, -1] = 0
    //a bắt đầu từ 0
    ll queries; fi >> queries;
    while(queries--){
        ll a, b; fi >> a >> b;
        ll ans = pref[b] - pref[a - 1];
        cout << ans << endl;
    }
}