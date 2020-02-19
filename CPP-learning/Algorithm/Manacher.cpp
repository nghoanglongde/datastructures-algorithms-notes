//Thuật toán Manacher tìm chuỗi đối xứng dài nhất liên tiếp từ chuỗi đích, time complexity O(n)
//Ví dụ: abcdcbaabcd -> output: dcbaabcd
#include<iostream>
#include<string>
#include<algorithm>
#define maxN 10000000
using namespace std;

int main(){
    string a,b;
    cin >> a;
    int n = a.length();
    int cnt = 0;
    int left_dx_center;
    int result[maxN];// lưu độ dài đối xứng tại vị trí i

    //Định dạng lại chuỗi ví dụ abc -> ^.a.b.c.0
    b[0] = '^';
    b[++cnt] = '.';
    for(int i = 1;i <= n;i++){
        b[++cnt] = a[i - 1];
        b[++cnt] = '.';
    }
    b[++cnt] = 0;

    int center = 1, right = 1, res = 0; // center là tâm đối xứng, right là bán kính độ dài đối xứng
    for(int i = 2;i <= cnt;i++){
        left_dx_center = 2 * center - i;
        result[i] = (i < right) ? min(result[left_dx_center], right - i) : 0; //trường hợp vị trí i đang xét nằm trong chuỗi đối xứng với tâm center và bán kính right (center,right)
        while(b[i - 1 - result[i]] == b[i + 1 + result[i]]){
            result[i]++;
        }
        res = max(res,result[i]); //độ dài xâu đối xứng lớn nhất hiện tại là res
        if(i + result[i] > right){
            center = i;
            right = i + result[i];
        }
    }
    cout << res << endl;
}
