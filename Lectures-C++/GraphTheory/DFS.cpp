//Thuật toán tìm kiếm theo chiều sâu(DEPTH FIRST SEARCH)
//DFS luôn trả về đường đi có thứ tự từ điển nhỏ nhất
#include<iostream>
#include<vector>
#include<fstream>
using namespace std;

//Đây là code đồ thị được biểu diễn theo ma trận kề nên Time Complexity sẽ là 0(n + n^2) = 0(n^2)
//Nếu ta sử dụng danh sách kề thì đpt = 0(max(n,m))
//Sử dụng danh sách cạnh thì đpt = 0(m.n)
void DFS(int u, int n, vector<vector<bool>> &arr, vector<int> &Trace){
    for(int v = 1;v <= n;v++){
        if(arr[u][v] && Trace[v] == 0){
            Trace[v] = u;
            DFS(v, n ,arr, Trace);
        }
    }
}
void printResult(int f, int s, int n, vector<int> Trace){
    //Các đỉnh có thể đến được khi xuất phát từ s
    for(int i = 1;i <= n;i++){
        if(Trace[i] != 0){
            cout << i  << " ";
        }
    }
    cout << endl;
    //Đường đi có thứ tự từ điển ngắn nhất từ s -> f
    while(f >= s){
        if(f == s){
            cout << f;
            break;
        }
        cout << f << "<-";
        f = Trace[f];
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

    int n, m, s, f;//số đỉnh n, số cạnh m, đỉnh xuất phát s và đỉnh kết thúc f;
    fi >> n >> m >> s >> f;
    vector<vector<bool>> arr(n + 1,vector<bool>(n + 1, false)); 
    vector<int> Trace(n + 1,0);//truy vết
    
    for(int i = 1;i <= m;i++){
        int u, v;
        fi >> u >> v;
        arr[u][v] = arr[v][u] = true;
    }

    Trace[s] = -1;
    DFS(s, n, arr, Trace);
    printResult(f, s, n, Trace);
}
