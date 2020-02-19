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
void inputUndirectedGraph(int n,vector<vector<int>> graph){
    while(1){
        int i,j;
        cin >> i >> j; //Nhập 2 đỉnh có cạnh liên thuộc với nhau
        if(i == 0 || i > n){
            break;
        }
        graph[i - 1][j - 1]++;
        graph[j - 1][i - 1]++;
    }
    outputGrapth(n,graph);
}
//Đa đồ thị có hướng
void inputDirectedGraph(int n,vector<vector<int>> graph){
    while(1){
        int i,j;
        cin >> i >> j;
        if(i == 0 || i > n)
            break;
        graph[i - 1][j - 1]++;
    }
    outputGrapth(n,graph);
}

//===============================================================================================

//Cài đặt đồ thị dưới dạng danh sách cạnh(Edge List)
//bằng mảng
void inputEdgeList(int n){
    EDGE graph[maxN];
    int edge;
    cin >> edge; //nhập số lượng cạnh
    for(int i = 0;i < edge;i++){
        cin >> graph[i].u >> graph[i].v; //nhập 2 đỉnh u và v
    }
}

//============================================================================================

//Cài đặt đồ thị dưới dạng danh sách kề(Adjacency List)
//Danh sách kề được mô tả khá chi tiết trong sách của thầy Hoàng nên mình sẽ ko code lại nữa

int main(){
    int n;
    cin >> n;//số đỉnh trong đồ thị

    //đồ thị dưới dạng ma trận
    vector<vector<int>> graph(n,vector<int>(n,0));
    inputUndirectedGraph(n,graph);
    cout << endl;
    cout << "==================================================" << endl;
    //inputDirectedGraph(n,graph);
    return 0;
}