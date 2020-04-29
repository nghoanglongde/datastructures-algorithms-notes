#include<iostream>
#include<vector>
#define maxN 1000
using namespace std;

struct EDGE{
    int u;
    int v;
};

void outputGrapth(int n,vector<vector<int>> graph){
    for(int i = 0;i < n;++i){
        for(int j = 0;j < n;++j){
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

//ĐA ĐỒ THỊ(từ u tới v có nhiều hơn 1 cạnh liên thuộc), dưới dạng ma trận(Adjacency Matrix)
//Vì đơn đồ thị cũng là đa đồ thị nên mình sẽ thao tác với đa đồ thị
//Đa đồ thị vô hướng
//Cài đặt dưới dạng ma trận kề
void inputUndirectedGraph(int n, int m){
    vector<vector<int>> graph(n,vector<int>(n,0));
    for(int k = 1;k <= m;k++){
        int i,j;
        cin >> i >> j; //Nhập 2 đỉnh có cạnh liên thuộc với nhau
        graph[i - 1][j - 1]++;
        graph[j - 1][i - 1]++;
    }
    outputGrapth(n,graph);
}
//Đa đồ thị có hướng
void inputDirectedGraph(int n,int m){
    vector<vector<int>> graph(n,vector<int>(n,0));
    for(int k = 1;k <= m;k++){
        int i,j;
        cin >> i >> j;
        graph[i - 1][j - 1]++;
    }
    outputGrapth(n,graph);
}

//===============================================================================================

//Cài đặt đồ thị dưới dạng danh sách cạnh(Edge List)
//bằng mảng
void inputEdgeList(int n,int m){
    EDGE graph[maxN];
    for(int i = 0;i < m;i++){
        cin >> graph[i].u >> graph[i].v; //nhập 2 đỉnh u và v
    }
}

//============================================================================================

//Cài đặt đồ thị dưới dạng danh sách kề(Adjacency List)
//Danh sách kề được mô tả khá chi tiết trong sách của thầy Hoàng
//Đa đồ thị vô hướng
void inputAdjList(int n, int m){
    vector<int> list[n];
    for(int i = 1;i <= m;i++){
        int u, v;
        cin >> u >> v;
        list[u].push_back(v);
        list[v].push_back(u);
    }
   
}

int main(){
    int n, m;//n đỉnh và m cạnh
    cin >> n >> m;//số đỉnh và số cạnh trong đồ thị

    //đồ thị dưới dạng ma trận kề
    inputUndirectedGraph(n, m);
    cout << endl;
    cout << "==================================================" << endl;
    inputDirectedGraph(n, m);

    //đồ thị dưới dạng danh sách cạnh
    inputEdgeList(n, m);
    //đồ thị dưới dạng danh sách kề
    inputAdjList(n,m);
    return 0;
}