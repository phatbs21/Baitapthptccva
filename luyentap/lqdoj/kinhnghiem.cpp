#include <bits/stdc++.h>

using namespace std;

const int nmax = 201;
const int INF = 1e9;

int n, m, a[nmax][nmax], f[nmax * 2][nmax][nmax];

int main()
{

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int p = 3; p < m + n; p++) 
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++)
                f[p][i][j] = -INF;
    f[2][1][1] = 0;

    for (int k = 3; k < m + n; k++)
    {
        int l = max(1, k - m);
        int r = min(n, k - 1);
        for (int i = l; i <= r; i++)
            for (int j = i + 1; j <= r; j++)
            {
                f[k][i][j] = max({f[k - 1][i][j],
                                  f[k - 1][i - 1][j], 
                                  f[k - 1][i][j - 1],
                                  f[k - 1][i - 1][j - 1]});
                f[k][i][j] += a[i][k - i] + a[j][k - j];
            }
    }
    cout << f[m + n - 1][n - 1][n];
}
