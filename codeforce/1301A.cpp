#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a, b, c;
        int dem = 0;
        cin >> a >> b >> c;
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] == b[i] && a[i] == c[i])
                break;
            else if ((a[i] == c[i] || b[i] == c[i]))
                dem++;
        }
        if (dem == a.length())
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}