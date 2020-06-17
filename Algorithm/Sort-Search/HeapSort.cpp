#include <iostream>
#include <vector>
using namespace std;

//hàm format lại cây heap thành max heap, 2 nút con luôn nhỏ hơn nút cha
void bottomUpMAXHeapify(vector<int> &arr, int n, int node){
    int compare ,parent = node;
    int left_child = 2 * parent + 1;
    int right_child = (2 * parent) + 2;
    if (left_child < n && right_child < n){
        if (arr[left_child] >= arr[right_child]){
            compare = left_child;
        }
        else{
            compare = right_child;
        }

        if(arr[parent] < arr[compare]){
            parent = compare;
        }
    }
    else{
        if (right_child < n && arr[right_child] > arr[parent]){
            parent = right_child;
        }
        else if (left_child < n && arr[left_child] > arr[parent]){
            parent = left_child;
        }
    }
    if (parent != node){
        swap(arr[parent], arr[node]);
        bottomUpMAXHeapify(arr, n, parent);
    }
}

int main(){
    vector<int> arr;
    vector<int> heap_max;
    int num_element; cin >> num_element;

    for (int i = 0; i < num_element; i++){
        int value;
        cin >> value;
        arr.push_back(value);
    }
    //format lại theo dạng max heap
    for (int i = num_element / 2 - 1; i >= 0; i--){
        bottomUpMAXHeapify(arr, num_element, i);
    }

    //cây max heap
    for (int i = 0; i < num_element; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    
    for (int i = num_element - 1; i > 0; i--){
        //sort lại cây heap
        swap(arr[0], arr[i]);
        bottomUpMAXHeapify(arr, i, 0);
    }

    //đã sort mảng lại theo cây max heap
    for (int i = 0; i < num_element; i++){
        cout << arr[i] << " ";
    }
}