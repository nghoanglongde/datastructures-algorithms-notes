#include <bits/stdc++.h>
#define FOR(n) for(int i = 0;i < (n); ++i)
using namespace std;
 
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int sum = 0;
		bool odd = false, even = false;
		FOR(n){
			int x;
			cin >> x;
			sum += x;
			odd = (odd || x % 2 != 0) ? true : false;
			even = (even ||  x % 2 == 0) ? true: false;
		}
		if (sum % 2 != 0 || (odd && even)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	
	return 0;
}