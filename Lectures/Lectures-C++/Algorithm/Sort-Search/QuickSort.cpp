#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
ll partition (vector<ll> &arr, ll low, ll high)
{
    ll pivot = arr[high];
    ll left = low;
    ll right = high - 1;
    while(true){
        while(left <= right && arr[left] < pivot) left++;
        while(right >= left && arr[right] > pivot) right--;
        if (left >= right) break;
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
    swap(arr[left], arr[high]);
    return left;
}

void QuickSort(vector<ll> &arr, ll low, ll high)
{
    if (low < high)
    {
        ll pi = partition(arr, low, high);
        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}

int main(){
    ll n; cin >> n;
    vector<ll> arr(n);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    QuickSort(arr, 0, n - 1);
    for(auto x: arr){
        cout << x << " ";
    }
}