#include <iostream>
using namespace std;
 
typedef long long ll;
 
int main(void) {
	ll N, A, B;
	cin >> N >> A >> B;
 
	ll k = N / (A + B);
	ll m = N % (A + B);
	ll ans = (ll)0;
	if (m < A)
		ans = m;
	else
		ans = A;
	ans += k * A;
 
	cout << ans << '\n';
	return 0;
}