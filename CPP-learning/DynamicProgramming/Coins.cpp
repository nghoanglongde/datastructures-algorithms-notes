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
    vector<int> Value;//mảng giá trị mỗi đồng xu
    for(int i = 0;i < n;i++){
        int temp;
        cin >> temp;
        Value.push_back(temp);
    }
    cout << DP(Value,Min,S,n) << endl;
    cout << DPToHop(Value,Min,S,n);
}