//Bài toán về dãy con tăng dài nhất (Longest increasing subsequence)
//Ví dụ: 1 2 3 8 9 4 5 6 20 9 10 -> dãy con dài nhất số phần tử là 8/1 2 3 4 5 6 9 10

#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#define maxN (int)1e18
using namespace std;

//Cách này dùng QHĐ thuần,2 loop nên Time Complexity = 0(n^2)
int DP(int n, vector<int> arr){
    vector<int> F(n);
    int result = 1;
    F[0] = 1;
    for(int i = 1;i < n;i++){
        F[i]  = 0;
        for(int j = 0;j < i;j++){
            if(arr[i] > arr[j])
                F[i] = max(F[i],F[j] + 1);
        }
        result = max(result,F[i]);
    }
    return result;
}

//Cách này kết hợp chặt nhị phân, Time complexity còn lại O(nlogn)
int DPWBS(int n,vector<int> arr){
    vector<int> F(n,maxN);
    int result = 1;
    F[0] = -maxN;
    for(int i = 0;i < arr.size();i++){
        int x = arr[i];
        int k = lower_bound(F.begin(),F.end(),x) - F.begin();
        F[k] = x;
        result = max(result,k);
    }
    return result;
}

int main(){
    //dữ liệu đặt trong file input.txt rồi đọc file ra
    ifstream fi;
    fi.open("input.txt");
    if(!fi){
        cout << "can't open this file";
        return 0;
    }   
    int n;
    vector<int> arr;
    fi >> n;
    for(int i = 0;i < n;i++){
        int temp;
        fi >> temp;
        arr.push_back(temp);
    }
    cout << DP(n,arr) << endl;
    cout << DPWBS(n,arr);
}
