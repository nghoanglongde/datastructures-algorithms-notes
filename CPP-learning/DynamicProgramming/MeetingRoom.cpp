/*Bài toán Arrange meeting room là dạng bài toán sắp xếp lịch cho một phòng họp theo thời gian
Ví dụ: Project 1: Ai = 6 - Bi = 8,
                  Ai = 7 - Bi = 8,
                       8        9
                       6        7
                       8        11
                       9        11*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<queue>
using namespace std;
struct TIME{
    int A;
    int B;
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
        original_trace[i] = trace[i];
        trace[i] = false;
    }
}

//Quy hoạch động cơ bản, bài này làm quy hoạch động Time Complexity = O(n^2), nên thảm khảo thuật toán tham lam O(nlogn)
//do có thêm truy vêt là 0(n^3)
void DP(vector<TIME> project,int n){
    //sort lại lịch
    sort(project.begin(),project.end(),functionSort);
    vector<int> F(n);
    vector<bool> trace(n,false);
    vector<bool> original_trace(n,false);
    int result = 1;
    F[0] = 1;
    for(int i = 1;i < n;i++){
        F[i] = 1;
        trace[i] = true;
        for(int j = 0;j < i;j++){
            if(project[i].A >= project[j].B && (F[i] < F[j] + 1)){
                trace[j] = true;
                F[i] = F[j] + 1;
            }
        }
        if(result < F[i]){
            result = F[i];
            Trace(original_trace,trace,n);
        }
    }

    //in ra kết quả
    cout << result << endl;
    int j = 1;
    for(int i = 0;i < n;i++){
        if(original_trace[i]){
            TIME temp = project[i];
            cout << j++ << ": " << temp.A << " " << temp.B << endl;
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
        int time_begin,time_end;
        fi >> time_begin >> time_end;
        project[i].A = time_begin;
        project[i].B = time_end;
    }
    DP(project,n);
}