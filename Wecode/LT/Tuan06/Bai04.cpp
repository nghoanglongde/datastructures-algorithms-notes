#include<iostream>
#include<fstream>
#include<string>
using namespace std;

typedef long long ll;

void Shift(ll a[], ll left , ll right, ofstream &fout, ll check) {
	ll i = left, j = 2 * i + 1;
	ll x = a[i];
	while (j <= right) {
		if (j < right) {
			if (a[j] > a[j + 1]) {
				j++;
			}
		}
			if (a[j] >= x) {
				return;
			}
		
			else {
				a[i] = a[j];
				a[j] = x;
				if (check) {
					fout << i << " " << j << endl;
				}
				i = j;
				j = 2 * i + 1;
				x = a[i];
			}
		
	}
}
void CreateHeap(ll a[], ll n, ofstream &fout) {
	ll l = n / 2 - 1;
	while (l >= 0) {
		Shift(a, l, n - 1,fout,1);
		l--;
	}
}
void HeapSort(ll a[], ll n, ofstream &fout) {
	ll r = n - 1;
	CreateHeap(a, n,fout);
	while (r >= 0) {
		ll temp = a[0];
		a[0] = a[r];
		a[r] = temp;
		r--;
		if (r > 0) {
			Shift(a, 0, r,fout ,0);
		}
	}
}
int main()
{
	ofstream fout;
	ifstream fin;
	fout.open("output.txt");
	ll n;
	cin >> n;
	ll *a = new ll[n];
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << "Day truoc khi sap xep: ";
	for (ll i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	HeapSort(a, n, fout);
	cout << "Day sau khi sap xep: ";
	for (ll i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	cout << "Cac hoan vi duoc thuc hien trong heap:\n";
	fin.open("output.txt");
	while (!fin.eof()) {
		string a;
		getline(fin, a);
		cout << a << endl;
	}
	return 0;
}