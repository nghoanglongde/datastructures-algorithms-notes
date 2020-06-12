typedef long long ll;

void xuat(ll *arr, ll n){
  for(ll i = 0;i < n;i++){
    cout << arr[i] << " ";
  }
}

void insertionsort(ll *arr, ll n){
    ll i, key, j;
   for (i = 1; i < n; i++){
     cout << "Vi tri chen cua a[" << i << "] la ";
       key = arr[i];
       j = i-1;
       while (j >= 0 && arr[j] < key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
       cout << j + 1 << endl;
       xuat(arr, n);
       cout << endl;
   }
}
int main() {
  ll n; cin >> n;
  if(n == 0){
    cout << "Mang rong.";
    return 0;
  }
  ll *arr = new ll[n];
  for(ll i = 0;i < n;i++){
    cin >> arr[i];
  }
  cout << "Mang truoc khi sap xep la: ";
  xuat(arr, n);
  cout << endl;
  insertionsort(arr, n);
  cout << "Mang sau khi sap xep la: ";
  xuat(arr, n);
}