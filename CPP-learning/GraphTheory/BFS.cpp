//Thuật toán tìm kiếm theo chiều rộng(BREADTH FIRST SEARCH)
//BFS luôn trả về một đường đi ngắn nhất(đi qua ít cạnh nhất)
#include<iostream>
#include<vector>
#include<fstream>
#include<queue>
using namespace std;

//Đây là code đồ thị được biểu diễn theo ma trận kề nên Time Complexity sẽ là 0(n + n^2) = 0(n^2)
//Nếu ta sử dụng danh sách kề thì đpt = 0(max(n,m))
//Sử dụng danh sách cạnh thì đpt = 0(m.n)
void BFS(int n, queue<int> &nodes, vector<vector<bool>> arr, vector<int> &Trace){
    while(!nodes.empty()){
        int u = nodes.front();
        nodes.pop();
        for(int v = 1;v <= n;v++){
            if(arr[u][v] && Trace[v] == 0){
                nodes.push(v);
                Trace[v] = u;
            }
        }
    }
    cout << endl;
}
void printResult(int f, int s, int n, vector<int> Trace){
    //Các đỉnh có thể đến được khi xuất phát từ s
    for(int i = 1;i <= n;i++){
        if(Trace[i] != 0){
            cout << i  << " ";
        }
    }
    cout << endl;
    //Đường đi ngắn nhất từ s -> f
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
    queue<int> nodes; //danh sách đỉnh u
    vector<vector<bool>> arr(n + 1,vector<bool>(n + 1, false)); 
    vector<int> Trace(n + 1,0);//truy vết
    
    for(int i = 1;i <= m;i++){
        int u, v;
        fi >> u >> v;
        arr[u][v] = arr[v][u] = true;
    }
    Trace[s] = -1;
    nodes.push(s);
    BFS(n, nodes, arr, Trace);
    printResult(f, s, n, Trace);
}
