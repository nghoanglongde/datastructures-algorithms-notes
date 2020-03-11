//Bài toán tìm dãy con có tổng bằng S các phần tử có thể không liên tiếp như ví dụ ở dưới, bài toán này có liên hệ
//với bài toán tổ hợp, tính tổng số cách có thể có được để chọn các phần tử có tổng bằng S, có thể không liên tiếp ở file Coins.cpp
//Khác ở chỗ bài toán này là bài toán con nhỏ của bài đó, vì cách làm bài này chỉ tính 1 + 2 = 3, còn ở file Coins.cpp nó tính cả
//1 + 1 + 1 = 3
//còn 1 dạng bài toán có tổng bằng S các phần tử liên tiếp ta sẽ giải bằng hash map ở ví dụ khác
//Ví dụ: 1 2 6 3 5 với S = 6 -> có dãy con có tổng bằng S, nếu có nhiều đáp án ví dụ: 1 2 3, 6 và 1 5 thì chỉ cần 
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
void DP(vector<int> arr,vector<vector<int>> F){
    int pos = 0;
    for(int k = 1;k <= S;++k){
        for(int i = 1;i <= n;++i){
            if(k >= arr[i]){
                if(F[k - arr[i]][i] || F[k - 1][i]) //nếu có trường hợp s(6) - arr[i] tồn tại ở những vị trước trước arr[i] như
                //ở trên là 1 + 2 khi ta đang xét vị trí arr[i] = 3 và s = 6
                    F[k][i] = 1;
            }
            cout << F[k][i] << " ";
        }
        cout << endl;
    }

    for(int i = 1;i <= n;++i){
        if(F[S][i] == 1){
            pos = i;
            break;
        }
    }
    if(pos)
        Trace(pos,arr,F);//in ra 1 trường hợp
    //muốn đếm số cách tạo dãy con có tổng bằng S(các phần tử có thể không liên tiếp) thì chỉ cần đếm F[1...n][S] = 1 thì 
    //dem + 1
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
    vector<vector<int>> F(S + 1,vector<int>(n + 1,0));//khởi tạo bảng chi phí
    for(int i = 0;i <= S;i++){
        for(int j = 0;j <= n;j++){
            if(i == 0)
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