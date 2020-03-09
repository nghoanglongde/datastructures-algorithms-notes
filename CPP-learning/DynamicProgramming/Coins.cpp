#include<iostream>
#include<algorithm>
#include<fstream>
#include<vector>
using namespace std;

//bài toán tìm số đồng xu nhỏ nhất để tổng giá trị của chúng bằng S(bài toán tối ưu)
//Ví dụ: Cho các đồng xu với giá tiền 1, 3 và 5. Và S = 11 -> output: 3 đồng
int DP(vector<int> Value, vector<int> Min,int S,int n){
    Min[0] = 0;
    for(int i = 1;i <= S;++i){
        for(int j = 0;j < n;++j){
            if(Value[j] <= i && Min[i - Value[j]] + 1 < Min[i])
                Min[i] = Min[i - Value[j]] + 1;
        }
    }
    return Min[S];
}

//bài toán tìm số cách khác nhau để chọn ra các đồng xu sao cho tổng khối lượng của chúng là S.(bài toán tổ hợp)
//xét luôn cả các trường hợp bị lặp, trùng
int DPToHop(vector<int> Value, vector<int> Min,int S,int n){
    vector<int> DP(S + 1,0);//S + 1 do mảng chạy từ 0
    DP[0] = 1;
    for(int i = 1;i <= S;++i){
        for(int j = 0;j < n;++j){
            if(Value[j] <= i){
                DP[i] = DP[i] + DP[i - Value[j]];
            }
            cout << DP[i] << " ";
        }
        cout << endl;
    }
    return DP[S];

}
//Cách tìm tổ hợp trên sẽ bị trùng các hoán vị, ví dụ (1,3) và (3,1) đều bằng 4, nên ta có bài toán như sau
//Tìm số cách khác nhau để chọn ra các đồng xu sao cho tổng khối lượng của chúng là S. Với điều kiện, các cách lấy
//đồng xu là hoán vị của nhau không được coi là khác nhau.

//Điểm khác biệt giữa bài toán tổ hợp với tổ hợp không lặp nằm ở chỗ, nếu xét {1,3,5} với
//S = 6, tới DP[3] thì tổ hợp lặp nó sẽ gộp tất cả các cách có thể có, còn bảng cơ sở của tổ
//hợp không lặp nó có khi lấy số 1 nó sẽ có bao nhiêu trường hơp, lấy số 3 có bao nhiêu trường 
//hợp, từ đó lấy làm cơ sở để ta xây dựng DP[4] ta sẽ chọn trường hợp DP[3] nào

//Các bài toán tổ hợp có mối liên hệ với nhau, bài này có mối liên hệ với bài toán cái túi
void DPToHopKhongLap(vector<int> Value, int n, int S){
    vector<vector<int>> DP(n + 1,vector<int>(S + 1,0));
    for(int i = 1;i <= n;i++){
        DP[i][0] = 1;
    }
    for(int M = 1;M <= S;++M){
        for(int i = 1;i <= n;i++){
            int x = DP[i - 1][M];
            int y = (M - Value[i] >= 0) ? DP[i][M - Value[i]] : 0;
            DP[i][M] = x + y;
        }
    }
    for(int i = 0;i <= n;i++){
        for(int j = 0;j <= S;j++){
            cout << DP[i][j] << " ";
        }
        cout << endl;
    }
}
//Dưới đây là code = python cho bài toán tổ hợp tối ưu
// n, S = map(int, input().split())
// w = list(map(int, input().split()))

// dp = [[0 for _ in range(n)] for _ in range(S + 1)]
// for i in range(n):
//     dp[0][i] = 1

// for i in range(1, S + 1):
//     for j in range(n):
//         x = dp[i - w[j]][j] if i - w[j] >= 0 else 0 //có chọn đồng xu hiện tại có tổng bằng i
//         y = dp[i][j - 1] if j >= 1 else 0 //chọn các đồng xu trước nó có tổng bằng i
//         dp[i][j] = x + y


// print(dp[-][n - 1])
// # Kết quả tính toán với n = 3, w = [1, 3, 5] như sau:
// #  S = 0 |1 |2 |3 |4 |5 |6 |7 |8 |9 |10|11
// #  ------+--+--+--+--+--+--+--+--+--+--+--
// #  k = 1 |1 |1 |2 |2 |3 |4 |4 |5 |6 |7 |8


int main(){
    //dữ liệu đặt trong file input.txt rồi đọc file ra
    ifstream fi;
    fi.open("input.txt");
    if(!fi){
        cout << "can't open this file";
        return 0;
    }   

    int n,S; //nhập số lượng đồng xu và tổng S
    fi >> n >> S;
    vector<int> Min(S + 1,1e8);//S + 1 do mảng chạy từ 0
    vector<int> Value(n + 1,0);//mảng giá trị mỗi đồng xu
    for(int i = 1;i <= n;i++){
        int temp;
        fi >> temp;
        Value[i] = temp;
    }
    //cout << DP(Value,Min,S,n) << endl; //mình đang cho giá trị bắt đầu từ arr[1..], nếu muốn
    //cout << DPToHop(Value,Min,S,n);// xài 2 hàm này thì phải đổi lại
    DPToHopKhongLap(Value,n,S);
}