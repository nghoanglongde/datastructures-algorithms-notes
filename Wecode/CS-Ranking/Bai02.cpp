//tính diện tích hình chữ nhật lớn nhất giữa 2 mảnh hình chữ nhật dọc bên phải điểm lỗi và bên trái điểm lỗi, tương tự ta tính cho
//max hình chữ nhật bên trên và bên dưới điểm lỗi -> compare 2 max ta sẽ có được hình chữ nhật lớn nhất có được

#include<iostream>

using namespace std;

int areangang(int a, int b, int x, int y){
    int result;
    int temp = b/2;
    if(temp == 0){
        return 0;
    }
    else{
        if(y < temp){
            result = (b - 1 - y) * a;
        }
        else{
            result = y * a;
        }
    }
    return result;
}
int areadoc(int a, int b, int x, int y){
    int result;
    int temp = a/2;
    if(temp == 0){
        return 0;
    }
    else{
        if(x < temp){
            result = (a - 1 - x) * b;
        }
        else{
            result = x * b;
        }
    }
    return result;

}
int main(){
    int t; cin >> t;
    while(t--){
        int a, b, x, y;
        int result; 
        cin >> a >> b >> x >> y;
        if(a + b <= 2){
            cout << 0 << endl;
        }
        else{
            int area_ngang = areangang(a, b, x, y);
            int area_doc = areadoc(a, b, x, y);
            if(area_ngang > area_doc){
                result = area_ngang;
            }
            else{
                result = area_doc;
            }
        }
        cout << result << endl;
    }
}