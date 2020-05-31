//Bài toán tìm dãy con có tổng bằng S các phần tử có thể không liên tiếp
//Bài toán này có liên hệ với bài toán tổ hợp, tính tổng số cách có thể có được để chọn các phần tử có tổng bằng S,
//có thể không liên tiếp ở bài toán Coins


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
void DP(vector<int> arr){
    int pos = 0;
    vector<vector<int>> F(S + 1, vector<int>(n + 1, 0));
    vector<vector<int>> DP(S + 1, vector<int>(n + 1, 0));

    for(int j = 0;j <= n;j++){
        //với tổng = 0 thì lúc nào cũng chọn được 1 phần tử
        F[0][j] = 1;
    }

    for(int k = 1;k <= S;++k){
        for(int i = 1;i <= n;++i){
            if(k >= arr[i]){
                DP[k][i] = F[k - arr[i]][i - 1];
                //[i - 1] mang ý nghĩa là đã từng có trước đó vị trí [k - arr[i]] hay k hay ko chứ ko phải phần từ liền kề phía sau
            }
            else{
                DP[k][i] = 0; //trạng thái tại một vị trí, ban đầu hoặc S < arr[i] thì luôn = 0, khác nhau với bài toán coins chỗ này
                //bài toán coins trạng thái, ban đầu hoặc S < arr[i] thì nó sẽ là kết quả của bài toán trước đó DP[S][i - 1]
            }
            if(DP[k][i] || F[k][i - 1])
                F[k][i] = 1;
            cout << DP[k][i] << " ";
        }
        cout << endl;
    }

    //Truy vết
    for(int i = 1;i <= n;++i){
        if(DP[S][i] == 1){
            pos = i;
            break;
        }
    }
    if(pos)
        Trace(pos,arr,DP);//in ra 1 trường hợp
    else{
        cout << "Cant" << endl;
    }
}
int main(){
    //dữ liệu đặt trong file input.txt rồi đọc file ra
    ifstream fi;
    fi.open("SEQ.txt");
    if(!fi){
        cout << "can't open this file";
        return 0;
    } 
    fi >> n >> S;
    vector<int> arr(n + 1,0);
    for(int i = 1;i <= n;++i){
        int temp;
        fi >> temp;
        arr[i] = temp;
    }

    DP(arr);
}