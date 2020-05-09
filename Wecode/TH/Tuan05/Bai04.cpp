/*###Begin banned keyword - each of the following line if appear in code will raise error. regex supported
define
include
###End banned keyword*/

#include <iostream>
using namespace std;

//###INSERT CODE HERE -
void quickSort(int a[], int left, int right) {
	int i = left, j = right;
	int pivot = a[left + rand() % (right - left)];
	while (i <= j) {
		while (a[i] < pivot) ++i;
		while (a[j] > pivot) --j;

		if (i <= j) {
			swap(a[i], a[j]);
			++i;
			--j;
		}
	}
	if (left < j) quickSort(a, left, j);
	if (i < right) quickSort(a, i, right);
}

int main(){
    int n; cin >> n;
    int *cities = new int[n];
    for(int i = 0;i < n;++i){
        cin >> cities[i];
    }
    quickSort(cities, 0, n - 1);
    int q; cin >> q;
    int *queries = new int[q];
    for(int i = 0;i < q;++i){
        cin >> queries[i];
    }
    for(int i = 0;i < q;i++){
        if(queries[i] < cities[0]){
            cout << 0 << endl;
        }
        else{
            int left = 0;
            int right = n - 1;
            int mid = (left + right) / 2;
            while(left != mid && right != mid){
                if(cities[mid] > queries[i])
                    right = mid;
                else
                    left = mid;
                mid = (left + right) / 2;
            }
            if(cities[right] <= queries[i] && (right == n - 1)){
                cout << right + 1 << endl;
            }
            else{
                cout << right << endl;
            }
        }
    }
 
}