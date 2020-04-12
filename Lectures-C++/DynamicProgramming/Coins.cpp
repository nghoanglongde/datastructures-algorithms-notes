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
        for(int j = 1;j <= n;++j){
            if(Value[j] <= i && Min[i - Value[j]] + 1 < Min[i])
                Min[i] = Min[i - Value[j]] + 1;
        }
    }
    return Min[S];
}

//bài toán tìm số cách khác nhau để chọn ra các đồng xu sao cho tổng khối lượng của chúng là S, các đồng xu
//được chọn có thể không liên tiếp. Bài toán này khác với bài toán ở file SEQ đó là, bài này đếm số cách có thể
//có được, còn bài ở SEQ là tìm ra 1 cách để được tổng bằng S(bài toán tổ hợp)
//ví du: 1 3 5 với S = 5
//bài này gần gióng bài tìm dãy con có tổng bằng S
//xét luôn cả các trường hợp bị lặp, trùng
void DPToHop(vector<int> Value,int S,int n){
    // vector<int> DP(S + 1,0);//S + 1 do mảng chạy từ 0
    // DP[0] = 1;
    // for(int M = 1;M <= S;++M){
    //     for(int i = 1;i <= n;++i){
    //         if(Value[i] <= M){
    //             DP[M] = DP[M] + DP[M - Value[i]];//cộng tất cả trường hợp có thể có được
    //             //với S(1) thì chỉ có 1(vị trí thứ nhất) phù hợp -> DP[1] = 1
    //             //với S(2) thì chỉ có 1(vị trí thứ nhất) phù hợp -> DP[2] = 1 
    //             //với S(3) thì có 1(vị trí thứ nhất) phù hợp -> DP[3] = 1(1 + 1 + 1), 
    //             //3(vị trí 2) phù hợp -> DP[3] = 1 + 1 = 2(1 + 1 + 1 và 3 0)
    //             //với S(4) thì có 1(vị trí thứ 1) phù hợp -> DP[4] = 0 + 2, 3(vị trí 2) phù hợp -> DP[4] = 2 + 1 = 3
    //             //vậy có thể thấy tại S = 4 thì cách này tính bị lặp 1 3 và 3 1
    //         }
    //         cout << DP[i] << " ";
    //     }
    //     cout << endl;
    // }

    // đây là dùng bảng cơ sở 2 chiều, ta có thể thấy, hầu như cột chúng ta không cần, cột cố định là n, nên chỉ cần 
    // bảng cơ sở 1 chiều như ở trên là được
    vector<vector<int>> DP(S + 1,vector<int>(n + 1,0));
    for(int i = 0;i <= n;i++){
        DP[0][i] = 1; //Tổng bằng 0 thì luôn chọn được 1 vật trong arr[1...n]
    }

    for(int M = 1;M <= S;M++){
        for(int i = 1;i <= n;i++){
            DP[M][i] = DP[M][i - 1]; //trường hợp không tính giá trị tại vị trí hiện tại
            if(Value[i] <= M) //nếu vị trí hiện tại có giá trị <= tổng đang cần
                DP[M][i] = DP[M][i] + DP[M - Value[i]][n];
            cout << DP[M][i] << " ";
        }
        cout << endl;
    }
    cout << DP[S][n] << endl;
    cout << "=================================================" << endl;

}

//Cách tìm tổ hợp trên sẽ bị trùng các hoán vị, ví dụ (1,3) và (3,1) đều bằng 4, nên ta có bài toán như sau
//Tìm số cách khác nhau để chọn ra các đồng xu sao cho tổng khối lượng của chúng là S. Với điều kiện, các cách lấy
//đồng xu là hoán vị của nhau không được coi là khác nhau.

//Điểm khác biệt giữa bài toán tổ hợp với tổ hợp không lặp nằm ở chỗ, nếu xét {1,3,5} với
//S = 6, tới DP[3] thì tổ hợp lặp nó sẽ gộp tất cả các cách có thể có(1 1 1 và 3 0) xem ví dụ bảng cơ sở của tổ hợp
//lặp ở trên để hiểu, còn bảng cơ sở của tổ hợp không lặp khi lấy số 1 nó sẽ có bao nhiêu trường hơp, 
//lấy số 3 có bao nhiêu trường hợp, từ đó lấy làm cơ sở để ta xây dựng DP[4] ta sẽ chọn trường hợp DP[3] nào

//Các bài toán tổ hợp có mối liên hệ với nhau, bài này có mối liên hệ với bài toán cái túi
void DPToHopKhongLap(vector<int> Value, int n, int S){
    vector<vector<int>> DP(S + 1,vector<int>(n + 1,0));
    for(int i = 0;i <= n;i++){
        DP[0][i] = 1;//với tổng bằng 0 thì lúc nào cũng chọn được 1 cách, giả dụ đồng thứ 1 có giá trị là 1, bắt chọn
        //tổng bằng 0, thì ta luôn có thể chọn đồng = 0, đồng thứ 2 bằng 3, bắt chọn đồng 0 thì ta cũng có 1 cách chọn
        //để tổng bằng 0 đó là chọn đồng 0....
    }
    for(int M = 1;M <= S;++M){
        for(int i = 1;i <= n;i++){
            int x = DP[M][i - 1];//chưa chọn đồng thứ i
            int y = (M - Value[i] >= 0) ? DP[M - Value[i]][i] : 0; //chọn đồng thứ i
            DP[M][i] = x + y;

        }
    }
    for(int i = 1;i <= S;i++){
        for(int j = 1;j <= n;j++){
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
    DPToHop(Value,S,n);// xài 2 hàm này thì phải đổi lại
    DPToHopKhongLap(Value,n,S);
}