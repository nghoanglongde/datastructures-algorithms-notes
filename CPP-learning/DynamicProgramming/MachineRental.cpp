/*Bài toán cho thuê máy(machine rental):
Trung tâm tính toán hiệu năng cao nhận được đơn đặt hàng của n khách hàng. Khách hàng i muốn sử dụng máy trong khoảng
thời gian từ ai đến bi và trả tiền thuê là ci. Hãy bố trí lịch thuê máy để tổng số tiền thu được là lớn nhất mà
thời gian sử dụng máy của 2 khách hàng bất kì được phục vụ đều không giao nhau (cả trung tâm chỉ có một máy cho thuê).

Ví dụ: Project 1: Ai = 7 - Bi = 8   - Ci = 9,
               2  Ai = 7 - Bi = 8   - Ci = 4,
               3       8        9   - Ci = 5,
               4       6        7   - Ci = 3,
               5       9        11  - Ci = 2,
               6       9        11  - Ci = 5,

Vậy ouput -> 4 1 6

Hướng dẫn: đây là bài toán cải tiến của bài toán MeetingRoom, vui lòng xem lại bài MeetingRoom nếu bạn chưa suy nghĩ
được bài này

*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;

struct TIME{
    int A;
    int B;
    int C;
};

bool functionSort(TIME a, TIME b){
    if(a.B <= b.B){
        return true;
    }
    return false;
}

//Truy vết
void Trace(vector<bool> &original_trace, vector<bool> &trace,int n){
    for(int i = 0;i < n;i++){
        if(trace[i]){
            original_trace[i] = true;
        }
        else
            original_trace[i] = false;
    }
}

//Quy hoạch động cơ bản, bài này làm quy hoạch động Time Complexity = O(n^2), nên thảm khảo thuật toán tham lam O(nlogn)
//do có thêm truy vêt là 0(n^3)
void DP(vector<TIME> project,int n){
    //sort lại lịch
    sort(project.begin(),project.end(),functionSort);
    vector<int> Coins(n);
    vector<bool> trace(n,false);
    vector<bool> original_trace(n,false);
    long int result = 1, maxCoins = (int)-1e8;
    Coins[0] = project[0].C;
    for(int i = 1;i < n;i++){
        Coins[i] = project[i].C;
        trace[i] = true;
        for(int j = 0;j < i;j++){
            if(project[i].A >= project[j].B && (Coins[i] + Coins[j] > maxCoins)){
                trace[j] = true;
                maxCoins = Coins[i] + Coins[j];
                Coins[i] = Coins[i] + Coins[j];
                Trace(original_trace,trace,n);
            }
        }
        trace[i] = false;
    }

    //in ra kết quả
    cout << maxCoins << endl;
    int j = 1;
    for(int i = 0;i < n;i++){
        if(original_trace[i]){
            TIME temp = project[i];
            cout << j++ << ": " << temp.A << " " << temp.B << " " << temp.C << endl;
        }
    }
}

int main(){
    //dữ liệu đặt trong file input.txt rồi đọc file ra
    ifstream fi;
    fi.open("input.txt");
    if(!fi){
        cout << "can't open this file";
        return 0;
    }   

    int n;
    fi >> n; //số project trong 1 ngày theo thời gian
    vector<TIME> project(n);
    for(int i = 0;i < n;i++){
        int time_begin, time_end, cost;
        fi >> time_begin >> time_end >> cost;
        project[i].A = time_begin;
        project[i].B = time_end;
        project[i].C = cost;
    }
    DP(project,n);
}