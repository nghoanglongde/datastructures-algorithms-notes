#include<iostream>

using namespace std;

typedef long long ll;
void swap(ll &a, ll &b, ll i, ll j) {
	if (a != b) {
		ll temp = a;
		a = b;
		b = temp;
		//c << i + 1 << " " << j + 1 << endl;
	}
}
inline void QuickSort1(ll a[], ll left, ll right) {
	ll i = left, j = right;
	ll mid = a[(left + right) / 2];
	while (i <= j) {
		while (a[i] > mid) {
			i++;
		}
		while (a[j] < mid) {
			j--;
		}
		if (i <= j) {
			swap(a[i], a[j], i, j);
			i++;
			j--;
		}

	}
	if (left < j) {
		QuickSort1(a, left, j);
	}
	if (i < right) {
		QuickSort1(a, i, right);
	}
}
inline void QuickSort2(ll a[], ll left, ll right) {
	ll i = left, j = right;
	ll mid = a[(left + right) / 2];
	while (i <= j) {
		while (a[i] > mid) {
			i++;
		}
		while (a[j] < mid) {
			j--;
		}
		if (i <= j) {
			if (i != j) {
				cout << i + 1 << " " << j + 1 << endl;
			}
			swap(a[i], a[j], i, j);

			i++;
			j--;

		}

	}
	if (left < j) {
		QuickSort2(a, left, j);
	}
	if (i < right) {
		QuickSort2(a, i, right);
	}
}
void XuatMang(ll a[], ll n) {
	for (ll i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

int main()
{
	ll n;
	cin >> n;
	ll *a = new ll[n];
	ll *b = new ll[n];
	
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	cout << "Day truoc khi sap xep: ";
	
	XuatMang(a,n);
	QuickSort1(a, 0, n - 1);
	cout << "Day sau khi sap xep: ";
	XuatMang(a, n);
	cout << "Cac hoan vi duoc thuc hien trong Quick Sort:\n";
	QuickSort2(b, 0, n - 1);

	return 0;
}