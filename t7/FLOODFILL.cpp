#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("FLOODFILL.inp", "r", stdin);
    freopen("FLOODFILL.out", "w", stdout);
    int c[100];

    int n;

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }
    int f[n + 1][n + 1];
    int g[n + 1][n + 1];

    n = unique(c + 1, c + 1 + n) - c - 1;
    for (int l = n; l >= 1; --l)
    {
        for (int r = l + 1; r <= n; ++r)
        {
            f[l][r] = min(f[l + 1][r] + 1, g[l + 1][r] + (c[l] != c[r]));
            g[l][r] = min(g[l][r - 1] + 1, f[l][r - 1] + (c[l] != c[r]));
        }
    }
    cout << min(f[1][n], g[1][n]);
}