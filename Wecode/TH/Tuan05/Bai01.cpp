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
    for (int i = 0; i < n; i++){
	    for (int j = 0; j < n - 1; j++){
		    if (arr[j] < arr[j+1]) {
			    swap(arr[j], arr[j+1]);
		    }
        }
    }
    for(int i = 0;i < n;i++){
        cout << arr[i] << " ";
    }
}