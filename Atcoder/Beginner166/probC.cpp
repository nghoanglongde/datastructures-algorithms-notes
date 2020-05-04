#include<iostream>
#include<vector>

using namespace std;

int main(){
    int N, M; cin >> N >> M;
    vector<int> elevation(N + 1); //độ cao mỗi núi
    vector<int> adjency[N + 1]; //danh sách kề các đỉnh
    for(int i = 1;i <= N;++i){
        int H; cin >> H;
        elevation[i] = H;
    }
    for(int i = 0;i < M;++i){
        int A, B; cin >> A >> B;
        if(elevation[A] <= elevation[B]){
            //nếu độ cao của đỉnh núi A <= đỉnh núi B thì push đỉnh A kề đỉnh B
            adjency[A].push_back(B);
        }
        if(elevation[B] <= elevation[A]){
            //tương tự
            adjency[B].push_back(A);
        }
    }
    int result = 0;
    for(int i = 1;i <= N;i++){
        if(adjency[i].empty()){
            //nếu đỉnh đó rỗng -> ko có đỉnh nào cao hơn nó hoặc nó ko kề đỉnh nào -> kết quả + 1
            ++result;
        }
    }
    cout << result;
}