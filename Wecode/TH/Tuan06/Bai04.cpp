typedef long long ll;
double partition (double arr[], ll low, ll high)
{
    double pivot = arr[high];
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

void QuickSort(double arr[], ll low, ll high)
{
    if (low < high)
    {
        double pi = partition(arr, low, high);
        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}

int main(){
    ll t; cin >> t;
    while(t--){
        ll n, x, count_e = 0;
        cin >> n >> x;
        double *arr = new double[n];
        for(ll i = 0;i < n;i++){
            cin >> arr[i];
            if(arr[i] >= x){
                ++count_e;
            }
        }
        QuickSort(arr, 0, n - 1);
        double sum = 0;
        ll j = n - 1;
        for(ll i = 1;i <= n;i++){
            sum = sum + arr[j--];
            count_e = (count_e < i && ((sum * 1.0 / i) - x) >= 0) ? i : count_e;
        }
        cout << count_e << endl;
    }
}