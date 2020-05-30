typedef long long ll;

ll partition (ll arr[], ll low, ll high)
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

void quickSort(ll arr[], ll low, ll high)
{
    if (low < high)
    {
        ll pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(){
        ll n; cin >> n;
        ll *arr = new ll[n];
        for(ll i = 0;i < n;i++){
            cin >> arr[i];
        }
        quickSort(arr, 0, n - 1);
        for(ll i = 0;i < n;i++){
            cout << arr[i] << " ";
        }

}