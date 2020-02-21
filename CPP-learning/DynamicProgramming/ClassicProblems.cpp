#include<iostream>
#include<vector>
#define maxN 1000
using namespace std;

//bài toán dãy con đơn điệu tăng dài nhất
//ví dụ 1 2 3 4 5 7 9 8 6 5 10 12 -> output: 3 5 7 9
void problem1(){
    int n;
    cin >> n; //nhập số lượng phần tử
    vector<int> arr;
    int max_length = 1, dem = 1;
    int pos_left = 0,pos_right = 1;
    for(int i = 0;i < n;i++){
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }
    for(int i = 1;i < n;i++){
        if(arr[i] < arr[i - 1]){
            dem = 1;
        }
        else{
            dem++;
            if(max_length < dem){
                pos_left = i - max_length;//vị trí bắt đầu dãy đơn điệu tăng
                pos_right = i;//vị trí cuối cùng dãy đơn điệu tăng
                max_length = dem;
            }
        }
    }
    cout << max_length << endl;
    for(int i = pos_left;i <= pos_right;i++){
        cout << arr[i] << " ";
    }

}

//bài toán tìm số đồng xu nhỏ nhất để tổng giá trị của chúng bằng S(bài toán tối ưu)
void problem2(){
    int n,S; //nhập số lượng đồng xu
    cin >> n >> S;
    vector<int> Min(S + 1,1e8);//S + 1 do mảng chạy từ 0
    vector<int> Value;//mảng giá trị mỗi đồng xu
    for(int i = 0;i < n;i++){
        int temp;
        cin >> temp;
        Value.push_back(temp);
    }
    Min[0] = 0;
    for(int i = 1;i <= S;++i){
        for(int j = 0;j < n;++j){
            if(Value[j] <= i && Min[i - Value[j]] + 1 < Min[i])
                Min[i] = Min[i - Value[j]] + 1;
        }
    }
    cout << Min[S];
}

//bài toán tìm số cách khác nhau để chọn ra các đồng xu sao cho tổng khối lượng của chúng là S.(bài toán tổ hợp)
void problem3(){
    int n,S; //nhập số lượng đồng xu
    cin >> n >> S;
    vector<int> DP(S + 1,0);//S + 1 do mảng chạy từ 0
    vector<int> Value;//mảng giá trị mỗi đồng xu
    for(int i = 0;i < n;i++){
        int temp;
        cin >> temp;
        Value.push_back(temp);
    }
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
    cout << DP[S];

}

/*bài toán cái túi Trong siêu thị có n đồ vật (n≤1000), đồ vật thứ i có trọng lượng là W[i]≤10­00 và
giá trị V[i] ≤1000. Một tên trộm đột nhập vào siêu thị, tên trộm mang theo một cái túi có thể mang
được tối đa trọng lượng M (M≤1000). Hỏi tên trộm sẽ lấy đi những đồ vật nào để được tổng giá trị lớn nhất.*/
void problem4(){
    int n, max_weight;
    cin >> n >> max_weight;
    vector<int> weight_packages(n + 1,0);
    vector<int> value(n + 1,0);
    vector<vector<int>> DP(n + 1,vector<int>(max_weight + 1,0));
    for(int i = 1;i <= n;i++){
        cin >> weight_packages[i] >> value[i];
    }
    for(int M = 1;M <= max_weight;++M){
        for(int i = 1;i <= n;++i){
            DP[i][M] = DP[i - 1][M];
            if(value[i] <= M && DP[i][M] < (DP[i - 1][M - value[i]] + value[i])){
                DP[i][M] = DP[i - 1][M - value[i]] + value[i];
            }
        }
    }
    cout << DP[n][max_weight];
    
}

int main(){
    //problem1();
    //problem2();
    //problem3();
    problem4();
}