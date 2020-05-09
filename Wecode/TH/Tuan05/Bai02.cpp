/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -

int main(){
    int n; cin >> n;
    int *arr = new int[n];
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
        while (j >= 0 && arr[j] < key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }   
    for(int i = 0;i < n;i++){
        cout << arr[i] << " ";
    }
}
