/*
Giải thích kết quả ở ví dụ: Điểm cao nhất trên đường đi: 2
                            Điểm thất nhất trên đường đi: 0
                            output = 2 - 0 = 2
*/

//Chặt nhị phân + DFS
#include <string>
#include<stdio.h>
#include<cstring>
#include<iostream>
#include <algorithm>
using namespace std;
 
#define N 105
 
int vst[N][N], a[N][N], n, mn, mx;
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};//điều khiển tọa độ lên trên, xuống dưới,sang phải, trái
 
bool dfs(int u, int v) {
    vst[u][v] = 1; 
    if( u == n - 1 && v == n-1 )
        return 1;
    for(int i = 0; i < 4; ++i) {
        int x = u + dx[i], y = v + dy[i];
        if( x >= 0 && y >= 0 && x < n && y < n && !vst[x][y] && a[x][y] >= mn && a[x][y] <= mx )
            if(dfs(x,y))
                return 1;
    }
    return 0;
}
 
int main() { 
    cin >> n;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cin >> a[i][j];
        }
    }

    int res = (int) 1e9;
    for(mn = 0; mn <= a[0][0]; ++mn) {
        int L = 0, H = 120;
        //chặt nhị phân
        while( L <= H ) {
            int mid = (L+H)>>1;
            mx = mn+mid; //giới hạn đường đi
            memset(vst, 0, sizeof vst);
            bool ok = dfs(0,0);
            if( L == H ) {
                if( !ok ) L = 1000000000;
                break;
            }
            if(ok) H = mid;
            else L = mid + 1;
        }
        res = min(res, L);
    }
    cout << res;
    return 0;
}
 
