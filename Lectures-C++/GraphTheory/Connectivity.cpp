//Tính liên thông của đồ thị, tài liệu tham khảo: Giải thuật và lập trình Lê Minh Hoàng
#include<iostream>
#include<vector>
#include<fstream>
#include<queue>
using namespace std;


void BFS(int n, queue<int> &nodes, vector<vector<bool>> arr, vector<bool> &Trace){
    while(!nodes.empty()){
        int u = nodes.front();
        nodes.pop();
        for(int v = 1;v <= n;v++){
            if(arr[u][v] && Trace[v]){
                nodes.push(v);
                Trace[v] = false;
            }
        }
    }
}

void checkConnectivity(vector<vector<bool>> arr, vector<bool> Trace, int n, int m, ifstream &fi){
    //khởi tạo
    for(int i = 1;i <= m;i++){
        int u, v;
        fi >> u >> v;
        arr[u][v] = arr[v][u] = true;
    }
    for(int i = 1;i <= n;i++){
        arr[i][i] = true;
    }
    //đếm số thành phần liên thông của 1 đồ thị
    int count = 0;
    queue<int> nodes;
    for(int i = 1;i <= n;i++){
        if(Trace[i]){
            count = count + 1;
            nodes.push(i);
            Trace[i] = false;
            BFS(n, nodes, arr, Trace);
        }
    }
    cout << "Nums of connection: " << count << endl;
}

//thuật toán floy-warshall
void warshall(vector<vector<bool>> arr, vector<bool> Trace, int n, int m, ifstream &fi){
    //khởi tạo
    for(int i = 1;i <= m;i++){
        int u, v;
        fi >> u >> v;
        arr[u][v] = arr[v][u] = true;
    }
    for(int i = 1;i <= n;i++){
        arr[i][i] = true;
    }

    //thuật toán
    for(int k = 1;k <= n;k++){
        for(int u = 1;u <= n;u++){
            for(int v = 1;v <= n;v++){
                arr[u][v] = arr[u][v] || (arr[u][k] && arr[k][v]);
            }
        }
    }

    //truy vết in kết quả
    int count = 1;
    for(int u = 1;u <= n;u++){
        if(Trace[u]){
            cout << "Connected Component " << count++ << ": " << endl; 
            for(int v = 1;v <= n;v++){
                if(arr[u][v]){
                    cout << v << " ";
                    Trace[v] = false;
                }
            }
            cout << endl;
        }
    }
}

int main(){
    //đọc dữ liệu từ file
    ifstream fi;
    fi.open("input.txt");
    if(!fi){
        cout << "can't open this file";
        return 0;
    } 
    //khởi tạo
    int n, m;
    fi >> n >> m;

    vector<vector<bool>> arr(n + 1,vector<bool>(n + 1, false)); //ma trận kề
    vector<bool> Trace(n + 1,true); //truy vết
    
    //Chạy hàm nào thì phải cmt hàm kia lại
    //checkConnectivity(arr, Trace, n, m, fi); //đếm số thành phần liên thông trong graph
    warshall(arr, Trace, n, m, fi); //floy-warshall liệt kê các thành phần liên thông
    return 0;
}
