#include <bits/stdc++.h>
using namespace std;
int f[1001][1001];
int n, k, a[1001], s;
int kt(int x)
{
    return (x >= 0) ? x : (x + k);
}
int main()
{
    s = 0;
    //freopen("QBSEQ.inp", "r", stdin);
    //freopen("QBSEQ.out", "w", stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] %= k;
        s = (s + a[i]) % k;
    }
    f[0][0] = 0;
    for (int i = 1; i < k; i++)
    {
        f[0][i] = 1e9;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            f[i][j] = min(f[i - 1][j], f[i - 1][kt(j - a[i])] + 1);
        }
    }
    cout << n - f[n][s % k];
}
