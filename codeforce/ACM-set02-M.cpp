#include<iostream>
#include<algorithm>
using namespace std;

struct CAR{
    int a, b, ID; //a = số tiền phạt tùy theo ngày i, b = số ngày để xe i sửa xong, ID = thứ tự của xe giống thứ tự đc nhập vào
    float median; //trung bình tiền phạt mất trong 1 ngày, dựa vào đó ta có thể biết xe nào sẽ phải chi nhiều tiền nhất để ưu tiên sửa trước tiên
};

bool sortDecrease(const CAR &a, const CAR &b){
    return a.median > b.median;
}

int main(){
    int n; cin >> n;
    CAR *arr = new CAR[n];
    for(int i = 0;i < n;i++)
        cin >> arr[i].a;
    for(int i = 0;i < n;i++){
        cin >> arr[i].b;
        arr[i].ID = i + 1;
        arr[i].median = (1.0 * arr[i].a)/arr[i].b;
    }
    sort(arr, arr + n, sortDecrease); //xe nào median cao nhất sẽ được sửa đầu tiên vì để càng lâu ngày ta sẽ mất càng nhiều tiền
    long long day = 0, mn = 0;
    for(int i = 0;i < n;i++){
        day = day + arr[i].b;
        mn = mn + day * arr[i].a;
    }
    cout << mn << endl;
    for(int i = 0;i < n;i++){
        cout << arr[i].ID << " ";
    }
    delete []arr;
    return 0;
}