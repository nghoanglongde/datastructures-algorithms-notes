#include<iostream>
#include<algorithm>
#include<fstream>
#include<vector>
using namespace std;

//bài toán tìm số đồng xu nhỏ nhất để tổng giá trị của chúng bằng S(bài toán tối ưu)
//Ví dụ: Cho các đồng xu với giá tiền 1, 3 và 5. Và S = 11 -> output: 3 đồng
int DP(vector<int> Value, int S, int n){
    vector<int> Min(S + 1,1e8);//S + 1 do mảng chạy từ 0
    Min[0] = 0;
    for(int i = 1;i <= S;++i){
        for(int j = 1;j <= n;++j){
            if(Value[j] <= i && Min[i - Value[j]] + 1 < Min[i])
                Min[i] = Min[i - Value[j]] + 1;
        }
    }
    return Min[S];
}

//bài toán tìm số cách khác nhau để chọn ra các đồng xu sao cho tổng khối lượng của chúng là S, các đồng xu
//được chọn có thể bị lặp hoặc trùng, có quan tâm thứ tự (1, 3) và (3, 1) là 2 cách chọn khác nhau

// # Kết quả tính toán với n = 3, w = [1, 3, 5] như sau:
// P = 0 |1 |2 |3 |4 |5 |6 |7 |8 |9 |10|11
// #  ------+--+--+--+--+--+--+--+--+--+--+--
// #  k = 1 |1 |1 |2 |3 |5 |8 |12|19|30|47|74

int DPToHop(vector<int> Value,int S,int n){
    vector<int> DP(S + 1,0);
    DP[0] = 1; //với tổng bằng 0 luôn chọn được bất kì đồng nào
    for(int M = 1;M <= S;++M){
        for(int i = 1;i <= n;++i){
            if(Value[i] <= M){
                DP[M] = DP[M] + DP[M - Value[i]];//cộng tất cả trường hợp có thể có được
                //với S(1) thì chỉ có 1(vị trí thứ nhất) phù hợp -> DP[1] = 1
                //với S(2) thì chỉ có 1(vị trí thứ nhất) phù hợp -> DP[2] = 1 
                //với S(3) thì có (vị trí thứ nhất) phù hợp -> DP[3] = 1(1 + 1 + 1), 
                //với S(3) thì có (vị trí thứ 2) phù hợp -> DP[3] = 1 + 1 = 2(trường hợp 1 + 1 + 1 và 3 0)
                //với S(4) thì có (vị trí thứ 1) phù hợp -> DP[4] = 0 + DP[3] = 2, (vị trí thứ 2) phù hợp -> DP[4] = 2 + 1 = 3
                //vậy có thể thấy tại S = 4 thì cách này tính bị lặp 1 3 và 3 1
            }
        }
    }
    return DP[S];


}

//Cách tìm tổ hợp trên sẽ bị trùng các hoán vị, ví dụ (1,3) và (3,1) đều bằng 4, nên ta có bài toán như sau
//Tìm số cách khác nhau để chọn ra các đồng xu sao cho tổng khối lượng của chúng là S. Với điều kiện, các cách lấy
//đồng xu là hoán vị của nhau(không quan tâm thứ tự)

//Điểm khác biệt giữa bài toán tổ hợp với tổ hợp không lặp nằm ở chỗ, nếu xét {1,3,5} với
//S = 6, tới DP[3] thì tổ hợp lặp nó sẽ gộp tất cả các cách có thể có(1 1 1 và 3 0) còn bảng cơ sở của tổ hợp không lặp khi 
//thì khi chọn DP[3] ta sẽ có từng trường hợp riêng cho mỗi đồng DP[3][1] -> tổng bằng 3 tại đồng xu thứ 1(1) với trường hợp
//của nó là 1 1 1, DP[3][2] ->tổng bằng 3 tại đồng xu thứ 2(3) tường hợp của nó là 1 1 1 và 3 1, DP[3][3] -> tổng bằng 3 tại 
//đồng xu thứ 3(5) trường hợp của nó là kết quả tối ưu của DP[3][2] vì đồng xu thứ 3 ta ko thể chọn đc -> từ đó mới xây dựng 
//kết quả cho bài toán tiếp theo là DP[4]

//Kết luận: Chia 2 part cho bài toán ko lặp, part 1 -> số trường hợp có tổng bằng M khi chưa chọn đồng i(ta chọn đồng trước i là i - 1), 
//part 2 -> số trường hợp có tổng bằng M khi đã chọn đồng i -> cộng 2 part ta được kết quả cuối cùng

// # Kết quả tính toán với n = 3, w = [1, 3, 5] như sau:
// #  S = 0 |1 |2 |3 |4 |5 |6 |7 |8 |9 |10|11
// #  ------+--+--+--+--+--+--+--+--+--+--+--
// #  k = 1 |1 |1 |2 |2 |3 |4 |4 |5 |6 |7 |8

//Bài toán tổ hợp không lặp còn áp dụng cho bài toán Knapsack nhưng Knapsack là dạng tối ưu, không phải dạng tổng trường hợp

int DPToHopKhongLap(vector<int> Value, int n, int S){
    vector<vector<int>> DP(S + 1,vector<int>(n + 1,0));
    for(int i = 0;i <= n;i++){
        DP[0][i] = 1;//với tổng bằng 0 thì lúc nào cũng chọn được 1 cách
    }
    for(int M = 1;M <= S;++M){
        for(int i = 1;i <= n;i++){
            int x = DP[M][i - 1];//chưa chọn đồng thứ i
            int y = (M >= Value[i]) ? DP[M - Value[i]][i] : 0; //chọn đồng thứ i
            DP[M][i] = x + y;

        }
    }
    //in ra bảng kết quả
    // for(int i = 1;i <= S;i++){
    //     for(int j = 1;j <= n;j++){
    //         cout << DP[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    return DP[S][n];
}


int main(){
    ifstream fi;
    fi.open("Coins.txt");
    if(!fi){
        cout << "can't open this file";
        return 0;
    }   

    int n, S; //số lượng đồng xu và tổng S
    fi >> n >> S;
    vector<int> Value(n + 1,0);//mảng giá trị mỗi đồng xu
    for(int i = 1;i <= n;i++){
        int temp;
        fi >> temp;
        Value[i] = temp;
    }
    cout << DP(Value, S, n) << endl;
    cout << DPToHop(Value, S, n) << endl;
    cout << DPToHopKhongLap(Value,n,S) << endl;
}