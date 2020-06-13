typedef long long ll;
struct day{
    ll sun, rain;
    double average;
};

void bublesort(day *&arr, ll n){
    for(ll i = 0; i < n - 1; i++){
        for(ll j = i + 1; j < n; j++){
            if(arr[i].average >= arr[j].average){
                 swap(arr[i], arr[j]);
            }
        }
    }
}
int main(){
    ll n; cin >> n;
    day *arr = new day[n];
    for(ll i = 0;i < n;i++){
        cin >> arr[i].sun >> arr[i].rain;
        arr[i].average = ((arr[i].sun + arr[i].rain) * 1.0) / 2;
    }
    bublesort(arr, n);
    bublesort(arr, n);
    for(ll i = 0;i < n;i++){
        cout << arr[i].sun << " " << arr[i].rain << endl;
    }
}