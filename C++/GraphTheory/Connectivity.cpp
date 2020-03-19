//Tính liên thông của đồ thị
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

//Một đồ thị G được gọi là liên thông nếu giữa hai đỉnh u và v bất kì luôn có đường đi giữa chúng(không phải u nối với v mới gọi là có
//đường đi, mà là u -> k mà k -> v thì u -> v cũng gọi là có đường đi)
//Ngoài ra ta cũng phải phân biệt đồ thị đầy đủ, và đồ thị liên thông, đồ thị đầy đủ chắc chắn là đồ thị liên thông nhưng để một đơn
//đồ thị vô hướng là liên thông thì bắt buộc bao đóng của nó phải là đồ thị đầy đủ
bool checkConnectivity(int n, vector<bool> Trace){
    for(int i = 1;i <= n;i++){
        if(Trace[i])
            return false;
    }
    return true;
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
    vector<bool> Trace(n + 1,true);//truy vết
    
    for(int i = 1;i <= m;i++){
        int u, v;
        fi >> u >> v;
        arr[u][v] = arr[v][u] = true;
    }
    Trace[s] = false;
    nodes.push(s);
    BFS(n, nodes, arr, Trace);
    if(checkConnectivity(n, Trace))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}
