#include <iostream>
#include <vector>
using namespace std;

//hàm format lại cây heap thành max heap, 2 nút con luôn nhỏ hơn nút cha
void bottomUpMAXHeapify(vector<int> &arr, int node, int n){
    int parent = node;
    int left_child = 2 * parent + 1;
    int right_child = (2 * parent) + 2;
    if (left_child <= n && right_child <= n){
        if (arr[left_child] >= arr[right_child])
            parent = left_child;
        else
            parent = right_child;
    }
    else{
        if (right_child <= n && arr[right_child] > arr[parent]){
            parent = right_child;
        }
        else if (left_child <= n && arr[left_child] > arr[parent]){
            parent = left_child;
        }
    }
    if (parent != node){
        swap(arr[parent], arr[node]);
        bottomUpMAXHeapify(arr, parent, n);
    }
    else 
        return;
}

int main(){
    vector<int> arr;
    vector<int> heap_max;
    int num_element, n_sort;
    cin >> num_element;
    //thêm 1 node vào cây
    for (int i = 0; i < num_element; i++){
        int value;
        cin >> value;
        arr.push_back(value);
    }
    //format lại theo dạng max heap
    for (int i = num_element / 2 - 1; i >= 0; i--){
        bottomUpMAXHeapify(arr, i, num_element - 1);
    }

    n_sort = num_element - 1;
    for (int i = num_element - 1; i >= 0; i--){
        //sort lại cây heap
        swap(arr[i], arr[0]);
        heap_max.push_back(arr[i]);
        arr.pop_back();
        bottomUpMAXHeapify(arr, 0, --n_sort);
    }

    //cây max heap chưa sort
    for (int i = 0; i < num_element; i++){
        cout << heap_max[i] << " ";
    }
    cout << endl;

    //cây max heap đã sort lại
    for (int i = 0; i < num_element; i++){
        cout << arr[i] << " ";
    }
}