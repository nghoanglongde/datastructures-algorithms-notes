/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -
void swap(char *xp, char *yp)  
{  
    char temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  
  
void selectionSort(string &arr, int n)  
{  
    int i, j, min_idx;  
  
    for (i = 0; i < n-1; i++)  
    {  
        min_idx = i;  
        for (j = i+1; j < n; j++)  
        if ((int)arr[j] < (int)arr[min_idx])  
            min_idx = j;  
  
        swap(arr[min_idx], arr[i]);  
    }  
}  
int main(){
    int num_element; cin >> num_element;
    string text; cin >> text;
    selectionSort(text, num_element);
    for(int i = 0;i < num_element;i++){
        cout << text[i];
    }
}