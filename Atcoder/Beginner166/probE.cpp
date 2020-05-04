#include<iostream>
using namespace std;
int main(){
    int N; cin >> N;
    int *arr = new int[N + 1];
    for(int i = 1;i <= N;i++){
        cin >> arr[i];
    }
    int count = 0;
    for(int i = 2;i <= N;i++){
        int j = 1;
        while(1){
            int next_pos = j + i;
            if(next_pos > N){
                break;
            }
            else{
                if(arr[j] + arr[j + i] == i){
                    count++;
                }
            }
            ++j;
        }
    }
    cout << count;
}