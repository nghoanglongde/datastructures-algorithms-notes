#include <bits/stdc++.h>
using namespace std;

int N, K;
vector<int> d;
vector<vector<int>> A;
void input()
{
    vector<vector<int>> matrix;
    cin >> N >> K;
    d.resize(K);
    A.resize(K, vector<int>());
    for (int i = 0; i < K; i++)
    {
        cin >> d[i];
        A[i].resize(d[i]);
        for (int j = 0; j < d[i]; j++)
        {
            cin >> A[i][j];
        }
    }
}

void solve()
{
    int ans = 0;
    for (int i = 1; i <= N; i++)
    {
        bool have = false;
        for (auto v : A)
        {
            for (auto p : v)
            {
                //cout << p << " ";
                if (p == i)
                   have = true;
            }
        }
        if (!have)
            ans++;
    }
    cout << ans << endl;
}

int main()
{
    input();
    solve();
}
