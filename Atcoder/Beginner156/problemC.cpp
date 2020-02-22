//link: https://atcoder.jp/contests/abc156/tasks/abc156_c
#include<iostream>
#include<math.h>
using namespace std;
int main(){
	int n, sum = 0, result = 0,result2 = 0;
  	int arr[100];
  	float average;
    int average1,average2;
  	cin >> n;
  	for(int i = 0;i < n;++i){
    	int temp;
      	cin >> temp;
        arr[i] = temp;
      	sum = sum + temp;
    }
  	average = (sum * 1.0)/ n;
    average1 = ceil(average);
    average2 = floor(average);
  	for(int i = 0;i < n;++i){
      result = result + pow((arr[i] - average1),2);
      result2 = result2 + pow((arr[i] - average2),2);
    }
    if(result < result2)
      cout << result;
    else{
      cout << result2;
    }
}