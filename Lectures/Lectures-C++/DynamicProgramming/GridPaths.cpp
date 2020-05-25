//Bài toán tìm đường đi có tổng lớn nhất từ góc trên trái xuống góc dưới phải của một ma trận vuông n x n có hệ số, chỉ được đi xuống hoặc đi sang phải
//Các bạn có thể đọc đề trong cuốn sách Competitive programmer's handbook

#include<iostream>
#include<vector>
#include<fstream>

using namespace std;

typedef long long ll;

void solve(vector<vector<ll>> arr, ll n){
    vector<vector<ll>> sum(n + 1, vector<ll>(n + 1, 0)); //bảng cơ sở quy hoạch động

    //tại mỗi vị trí y dòng và x cột, do ta bắt buộc đi qua phải hoặc đi xuống dưới, nên kết quả bài toán con trước đó phụ thuộc vào
    //max của 2 hướng đi y - 1(đi xuống) hoặc x - 1(đi sang phải)
    //Đpt: O(n^2)
    for(int y = 1;y <= n;y++){
        for(int x = 1;x <= n;x++){
            sum[y][x] = max(sum[y][x - 1], sum[y - 1][x]) + arr[y][x];
        }
    }
    cout << sum[n][n] << endl;
}

int main(){
    fstream fi;
    fi.open("GridPaths.txt");
    if(!fi){
        cout << "Cant open this file" << endl;
        return 0;
    }
    ll n; fi >> n;
    //khởi tạo và nhập ma trận n x n
    vector<vector<ll>> arr(n + 1, vector<ll>(n + 1, 0));
    for(int y = 1;y <= n;y++){
        for(int x = 1;x <= n;x++){
            fi >> arr[y][x]; //y dòng và x cột
        }
    }
    solve(arr, n);
    return 0;
}
