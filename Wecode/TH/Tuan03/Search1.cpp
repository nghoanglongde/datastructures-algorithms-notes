#include<iostream>
using namespace std;

int main(){
    long long n, k;
    cin >> n >> k;
    int *arr = new int[n];
    for(int i = 0;i < n;i++){
        int data; cin >> data;
        arr[i] = data;
    }

    int left = 0;
    int right = n - 1;
    int i = (left + right) / 2;
    while(left != i && right != i){
        if(arr[i] <= k)
            left = i;
        else
            right = i;
        i = (left + right) / 2;
    }
    if(arr[left] == k || arr[right] == k){
        cout << "YES";
    }
    else{
        cout << "NO";
    }

}