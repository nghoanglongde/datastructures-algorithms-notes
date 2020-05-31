typedef long long ll;
void Nhap(ll a[], ll n)
{
	for (ll i = 0; i < n; i++)
		cin >> a[i];
}
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

void QuickSort(ll arr[], ll low, ll high)
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
    ll countE = 0;
    ll *a = new ll[n];
    Nhap(a,n);
    QuickSort(a,0,n-1);
    for(int i = n - 1;i >= 1;i--){
        countE += a[i] - a[i - 1] - 1;
    }
    cout << countE;
}