#include <bits/stdc++.h>
using namespace std;

//Heap dạng mảng
void insertNodeArr(vector<int> &arr, int n, int value)
{
    n = n + 1;
    arr.push_back(value);
    while (n > 1)
    {
        int parent = n / 2;
        if (arr[parent - 1] < arr.back())
        {
            swap(arr[parent - 1], arr.back());
            n = parent;
        }
        else
            return;
    }
}

//hàm format lại cây heap thành max heap, 2 nút con luôn nhỏ hơn nút cha
void bottomUpMAXHeapify(vector<int> &arr, int node, int n)
{
    int parent = node;
    int left_child = 2 * parent + 1;
    int right_child = (2 * parent) + 2;
    if (left_child <= n)
    {
        if (arr[left_child] > arr[parent])
            parent = left_child;
    }
    if (right_child <= n && arr[right_child] > arr[parent])
    {
        if (arr[right_child] > arr[parent])
            parent = right_child;
    }
    if (parent != node)
    {
        swap(arr[parent], arr[node]);
        bottomUpMAXHeapify(arr, parent, n);
    }
}


int main()
{
    vector<int> arr;
    vector<int> sorted;
    int num_element, n_sort;
    cin >> num_element;
    //thêm 1 node vào cây
    for (int i = 0; i < num_element; i++)
    {
        int value;
        cin >> value;
        insertNodeArr(arr, i, value);
    }
    //format lại theo dạng max heap
    for (int i = num_element / 2 - 1; i >= 0; i--)
    {
        bottomUpMAXHeapify(arr, i, num_element - 1);
    }

    // n_sort = num_element - 1;
    // //hàm delete 1 node khỏi cây
    //xong roi sorted lai
    // for(int i = num_element - 1;i >= 0; i--){
    //   swap(arr[i], arr[0]);
    //   sorted.push_back(arr[i]);
    //   arr.pop_back();
    //   bottomUpMAXHeapify(arr, 0, --n_sort);
    // }

    for (int i = 0; i < num_element; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    // for(int i = 0;i < num_element;i++){
    //   cout << sorted[i] << " ";
    // }
}