//Tìm đường đi ngắn nhất trong đồ thị vô hướng từ start -> end với dijkstra và ma trận kề

#include <iostream>
#include <vector>
using namespace std;

const int oo = (int)1e6;
int start_node, end_node; //đỉnh đầu và đỉnh cuối

void Result(vector<int> d, vector<int> Trace){

    cout << "Duong di ngan nhat tu " << start_node << " -> " << end_node << " = " << d[end_node] << endl;

    int i = Trace[end_node];
    cout << end_node << "<=";
    while (i != start_node)
    {
        cout << i << "<=";
        i = Trace[i];
    }
    cout << start_node;
}

void dijkstra(vector<vector<int>> matrix_d, int E, int V)
{
    vector<int> d(E + 1); //khoảng cách
    vector<bool> has_checked(E + 1, false);
    vector<int> Trace(E + 1); //truy vết
    int current_E;
    for (int i = 1; i <= E; ++i)
    {
        d[i] = matrix_d[start_node][i];
        Trace[i] = start_node;
    }
    d[start_node] = 0;
    has_checked[start_node] = true;
    Trace[start_node] = 0;
    while (!has_checked[end_node]){
        int minp = oo;
        //Tìm đỉnh có trọng số nhỏ nhất
        for (int v = 1; v <= E; v++){
            if ((!has_checked[v]) && minp > d[v])
            {
                current_E = v;
                minp = d[v];
            }
        }
        has_checked[current_E] = true;
        if (!has_checked[end_node]){
            //gán nhãn lại cho đỉnh
            for (int v = 1; v <= E; v++)
            {
                if ((!has_checked[v]) && d[v] > d[current_E] + matrix_d[current_E][v])
                {
                    d[v] = d[current_E] + matrix_d[current_E][v];
                    Trace[v] = current_E;
                }
            }
        }
    }
    Result(d, Trace);
}

int main(){
    int V, E;
    cin >> V >> E; //số đỉnh V và số cạnh E
    cin >> start_node >> end_node;
    vector<vector<int>> matrix_d(V + 1, vector<int>(V + 1, oo)); //ma trận chi phí khoảng cách giữa 2 đỉnh bất kì
    for (int i = 0; i < E; i++)
    {
        int u, v, d;
        cin >> u >> v >> d;
        matrix_d[u][v] = matrix_d[v][u] = d;
    }
    dijkstra(matrix_d, E, V);
}