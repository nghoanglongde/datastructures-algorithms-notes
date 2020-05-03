/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -

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
            right = i;
        else
            left = i;
        i = (left + right) / 2;
    }
    if(arr[left] == k || arr[right] == k){
        if(arr[left] == k){
            cout << left;
        }
        else{
            cout << right;
        }
    }
    else{
        cout << -1;
    }
}
