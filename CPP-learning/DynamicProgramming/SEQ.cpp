//Bài toán dãy con có tổng bằng S
//Ví dụ: 1 2 4 3 5 với S = 6 -> có dãy con có tổng bằng S, nếu có nhiều đáp án ví dụ: 1 2 3, 2 4 và 1 5 thì chỉ cần 
//in ra 1 đáp án
//bài này cơ sở qhđ có thể dùng mảng 1 chiều F[k - arr[i]] nhưng dùng mảng 1 chiều thì khó truy vết nên mình sẽ dùng mảng 
//2 chiều

#include<iostream>
#include<vector>
#include<math.h>
#include<fstream>

using namespace std;

int n, S;//n số và tổng S

void Trace(int pos, vector<int> arr,  vector<vector<int>> F){
    int temp = S;
    while(1){
        cout << arr[pos] << " ";
        temp = temp - arr[pos];
        if(temp == 0)
            break;
        for(int i = 1;i <= n;++i){
            if(F[i][temp]){
                pos = i;
                break;
            }
        } 
    }
    cout << endl;
}
void DP(vector<int> arr,vector<vector<int>> &F){
    int pos = 0;
    for(int i = 1;i <= n;++i){
        for(int k = 1;k <= S;++k){
            if(arr[i] <= k){
                if(F[i - 1][k - arr[i]] || F[i - 1][k])
                    F[i][k] = 1;
            }
        }
    }

    for(int i = 1;i <= n;++i){
        if(F[i][S] == 1){
            pos = i;
            break;
        }
    }
    if(pos)
        Trace(pos,arr,F);
}
int main(){
    //dữ liệu đặt trong file input.txt rồi đọc file ra
    ifstream fi;
    fi.open("input.txt");
    if(!fi){
        cout << "can't open this file";
        return 0;
    } 
    fi >> n >> S;
    vector<int> arr(n + 1,0);
    vector<vector<int>> F(n + 1,vector<int>(S + 1,0));//khởi tạo bảng chi phí
    for(int i = 0;i <= n;i++){
        for(int j = 0;j <= S;j++){
            if(j == 0)
                F[i][j] = 1;
        }
    }
    for(int i = 1;i <= n;++i){
        int temp;
        fi >> temp;
        arr[i] = temp;
    }

    DP(arr, F);
}