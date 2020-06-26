#include<iostream>
#include<vector>
#include<fstream>

using namespace std;
typedef long long ll;

/*
    Idea:
    Chia dữ liệu thành 2 phần, rồi tiếp tục lặp lại việc này ở các mảng đã chia
    Sau đó gộp các nửa đó thành một mảng đã được sắp xếp

*/
void Merge(vector<ll> &arr, ll left, ll mid, ll right){
    int num_1 = mid - left + 1;
    int num_2 = right - mid;
    vector<ll> part_1(num_1);
    vector<ll> part_2(num_2);
    for(ll i = 0;i < num_1;i++){
        part_1[i] = arr[left + i];
    }
    for(ll i = 0;i < num_2;i++){
        part_2[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, cur = left;
    while(i < num_1 || j < num_2){
        if(i > num_1){
            arr[cur++] = part_2[j++];
        }
        else if(j > num_2){
            arr[cur++] = part_1[i++];
        }
        else if(part_1[i] < part_2[j]){
            arr[cur++] = part_1[i++];
        }
        else if(part_1[i] > part_2[j]){
            arr[cur++] = part_2[j++];
        }
    }
}
void MergeSort(vector<ll> &arr, ll left, ll right){
    if(left < right){
        ll mid = (left + right) / 2;
        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);
        Merge(arr, left, mid, right);
    }
}

int main(){
    ifstream fi;
    fi.open("MS.txt");
    if(!fi){
        cout << "Cant open this file" << endl;
        return 0;
    }

    ll n; fi >> n;
    vector<ll> arr(n);
    for(ll i = 0;i < n;i++){
        fi >> arr[i];
    }
    MergeSort(arr, 0, n - 1);
    for(auto x: arr){
        cout << x << " ";
    }
}