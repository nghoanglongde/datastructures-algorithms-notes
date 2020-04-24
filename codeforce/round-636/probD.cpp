#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

int main(){
    int t; cin >> t;
    while(t--){
        vector<long long> arr;
        long long sum_have;
        long long num_change = 0;
        long long n, k;
        long long max_t = 0, min_t = (int)1e8;
        long long max_p = 0, min_p = (int)1e8;
        long long i_maxt, i_mint, i_maxp, i_minp;
        cin >> n >> k;
        for(int i = 0;i < n;i++){
            long long data; cin >> data;
            arr.push_back(data);
            if(i <= (n/2) - 1){
                if(max_t <= data){
                    max_t = data;
                    i_maxt = i;
                }
                if(min_t >= data){
                    min_t = data;
                    i_mint = i;
                } 
            }
            else{
                if(max_p <= data){
                    max_p = data;
                    i_maxp = i;
                }
                if(min_p >= data){
                    min_p = data;
                    i_minp = i;
                } 
            }
        }
        if(max_t >= max_p){
            long long temp = arr[n/2];
            arr[n/2] = min_p;
            arr[i_minp] = temp;
            if(arr[n/2] != temp)
                num_change++;
        }
        else{
            long long temp = arr[(n/2) - 1];
            arr[(n/2) - 1] = min_t;
            arr[i_mint] = temp;
            if(arr[(n/2) - 1] != temp)
                num_change++;
        }
        sum_have = arr[n/2] + arr[(n/2) - 1];
        int j = n - 1;
        for(int i = 0;i <= (n/2) - 2;i++){
            long long sum_two = arr[i] + arr[j];
            if(sum_have - sum_two != 0){
                long long compare = max(arr[i], arr[j]);
                if(sum_have - compare >= 1 && sum_have - compare <= k){
                    num_change = num_change + 1;
                }
                else if(sum_have - compare > k)
                {
                    num_change = num_change + 2;
                }
                else{
                    num_change = num_change + 1;
                }
            }
            --j;
            
        }
        cout << num_change << endl;

    }
}