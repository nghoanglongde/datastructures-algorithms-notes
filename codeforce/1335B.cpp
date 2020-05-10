#include <bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, a, b;
		cin >> n >> a >> b;
		for (int i = 0; i < n; ++i) {
            int ans = i % b;
            cout << (char)(ans + 'a');
		}
		cout << endl;
	}
	
	return 0;
}