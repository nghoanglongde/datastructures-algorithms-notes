#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

typedef long long ll;

/*
    Idea: 
    Chia dãy thành 2 phần, một phần lớn và một phần nhỏ
        .Chọn một khóa pivot
        .Những phần tử có giá trị lớn hơn pivot ta đặt nó vào phần lớn
        .Những phần tử có giá trị nhỏ hơn pivot ta đặt nó vào phần nhỏ
        .Gọi đệ quy sắp xếp 2 nửa
    
    Ta chọn vị trí khóa pivot bằng cách random một số nằm trong khoảng [left, right] như vậy sẽ đảm bảo đpt trung bình của QS là O(nlogn)
*/
void QuickSort(vector<ll> &arr, ll left, ll right){
    ll i = left, j = right;
    ll pivot = arr[left + rand() % (right - left + 1)];
    while(i <= j){
        //B1: đưa tất cả phần tử nhỏ hơn pivot sang bên trái, tất cả phần tử lớn hơn pivot sang bên phải
        while(arr[i] < pivot) ++i;
        while(arr[j] > pivot) --j;
        if(i <= j){
            swap(arr[i], arr[j]);
            ++i;
            --j;
        }
    }
    //Gọi đệ quy sắp xếp 2 nửa
    if(left < j) QuickSort(arr, left, j);
    if(i < right) QuickSort(arr, i, right);
}

int main(){
    ifstream fi;
    fi.open("QS.txt");
    if(!fi){
        cout << "Cant open this file" << endl;
        return 0;
    }

    ll n; fi >> n;
    vector<ll> arr(n);
    for(int i = 0;i < n;i++){
        fi >> arr[i];
    }
    QuickSort(arr, 0, n - 1);
    for(auto x: arr){
        cout << x << " ";
    }
}