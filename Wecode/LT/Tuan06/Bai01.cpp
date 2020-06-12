typedef long long ll;

void xuat(ll *arr, ll n){
    for(ll i = 0;i < n;++i){
        cout << arr[i] << " ";
    }
}
void selectionsort(ll *arr, ll n){
    ll i, j, min_idx;
    for (i = 0; i < n-1; i++){
        cout << "i=" << i << ":" << endl;
        min_idx = i;
        for (j = i+1; j < n; j++){
            if (arr[j] > arr[min_idx])
                min_idx = j;
        }
        cout << "Max = " << "a[" << min_idx << "] = " << arr[min_idx] << endl;
        if(min_idx != i){
            swap(arr[min_idx], arr[i]);
        }
        cout << "Mang sau khi sap xep " << i + 1 << " phan tu dau tien la: ";
        xuat(arr, n);
        cout << endl;
    }
}
int main(){
    ll n; cin >> n;
    ll *arr = new ll[n];
    if(n == 0){
        cout << "Mang rong.";
        return 0;
    }
    for(ll i = 0;i < n;++i){
        cin >> arr[i];
    }
    cout << "Mang truoc khi sap xep la: ";
    xuat(arr, n);
    cout << endl;
    selectionsort(arr, n);
    cout << "Mang sau khi sap xep la: ";
    xuat(arr, n);
}