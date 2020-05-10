#include <iostream> 
#include <math.h>  
using namespace std; 
int main() 
{ 
    long n; 
    int k;
    cin >> n >> k;
    int dig = (int)(floor(log(n)/log(k)) + 1);
    cout << dig; 
}