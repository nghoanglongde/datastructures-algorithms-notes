/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
using
###End banned keyword*/
#include <iostream>
#include <string>
using namespace std;

//###INSERT CODE HERE -
int main(){
    int n; cin >> n;
    string *arr = new string[n];
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    for (int i = 0; i < n - 1; i++){
	    for (int j = 0; j < n - i - 1; j++){
            string text_1 = arr[j];
            string text_2 = arr[j + 1];
            int gio_1 = (((text_1[0] - '0') * 10) + (text_1[1] - '0'));
            int gio_2 = (((text_2[0] - '0') * 10) + (text_2[1] - '0'));
		    if (gio_1 > gio_2){
			    string temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
		    }
            else if(gio_1 == gio_2){
                int phut_1 = (((text_1[3] - '0') * 10) + (text_1[4] - '0'));
                int phut_2 = (((text_2[3] - '0') * 10) + (text_2[4] - '0'));
                if(phut_1 > phut_2){
                    string temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
                else if(phut_1 == phut_2){
                    int giay_1 = (((text_1[6] - '0') * 10) + (text_1[7] - '0'));
                    int giay_2 = (((text_2[6] - '0') * 10) + (text_2[7] - '0'));
                    if(giay_1 > giay_2){
                        string temp = arr[j];
                        arr[j] = arr[j + 1];
                        arr[j + 1] = temp;
                    }
                }
            }
        
        }
    }
    for(int i = 0;i < n;i++){
        cout << arr[i] << endl;
    }
    
}

