#include<iostream>
using namespace std;

typedef long long ll;

struct PHANSO{
    ll tu;
    ll mau;
};
void nhap(ll n, PHANSO *&arr, PHANSO &target){
    for(ll i = 0;i < n;i++){
        cin >> arr[i].tu >> arr[i].mau;
    }
    cin >> target.tu >> target.mau;

}
void xuat(ll n, PHANSO *arr){
    for(ll i = 0;i < n;i++){
        cout << arr[i].tu << "/" << arr[i].mau << " ";
    }
}
bool checkMax(PHANSO a, PHANSO b){
    ll check = a.tu * b.mau - b.tu * a.mau;
    if(check > 0){
        return true;
    }
    return false;
}

bool checkEqual(PHANSO a, PHANSO b){
    ll check = a.tu * b.mau - b.tu * a.mau;
    if(check == 0){
        return true;
    }
    return false;
}

bool checkMin(PHANSO a, PHANSO b){
    ll check = a.tu * b.mau - b.tu * a.mau;
    if(check < 0){
        return true;
    }
    return false;
}
void selectionSort(PHANSO *&arr, ll n)
{
    ll i, j, min_idx;
    ll count = 1;
    if(n == 1){
        cout << "#STEP " << count << ":" << endl;
        xuat(n, arr);
        cout << endl;
    }
    else{
        for (i = 0; i < n-1; i++){
            cout << "#STEP " << count << ":" << endl;
            ++count;
            min_idx = i;
            for(j = i+1; j < n; j++){
                if (checkMin(arr[j], arr[min_idx]))
                    min_idx = j;
            }
            if(min_idx != i){
                swap(arr[min_idx], arr[i]);
            }
            xuat(n, arr);
            cout << endl;
        }
    }
}
int main(){
    ll n; cin >> n;
    PHANSO *arr = new PHANSO[n];
    PHANSO target;
    nhap(n, arr, target);
    selectionSort(arr, n);
    ll left = 0;
    ll right = n - 1;
    ll mid;
    do{
        mid = (left + right) / 2;
        cout << "[Left=" <<left + 1 << ", Mid=" << mid + 1 << ", Right=" << right + 1 << "]" << endl;
        if(checkMin(arr[mid], target)){
            left = mid + 1;
        }
        else{
            right = mid - 1;
        }
    }while(left <= right);
    if(checkEqual(arr[left], target)){
        cout << "Tim thay phan so bang X tai vi tri be nhat la: " << left + 1;
    }
    else if(checkEqual(arr[mid], target)){
        cout << "Tim thay phan so bang X tai vi tri be nhat la: " << mid + 1;
    }
    else if(checkEqual(arr[right], target)){
        cout << "Tim thay phan so bang X tai vi tri be nhat la: " << right + 1;
    }
    // if(checkEqual(arr[mid], target) || checkEqual(arr[left], target) || checkEqual(arr[right], target)){
    //     cout << "Tim thay phan so bang X tai vi tri be nhat la: " << mid + 1;
    // }
    else{
        cout << "Khong tim thay phan so bang X";
    }
}