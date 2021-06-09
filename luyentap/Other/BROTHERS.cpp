#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int dbrr = 202, MOD = 1e9 + 7;
int n, m, a[dbrr][dbrr], dp[2 * dbrr][dbrr][dbrr];
int kt(int k, int p1, int p2)
{
    int kq = -1e9;
    if (p1 == 1 && p2 == 1 && k == 2)
        return a[1][1];
    if (dp[k][p1][p2] != -1e9)
        return dp[k][p1][p2];
    if (k - p1 > 1 && k - p2 > 1)
        kq = max(kq, kt(k - 1, p1, p2));
    if (k - p1 > 1 && p2 > 1)
        kq = max(kq, kt(k - 1, p1, p2 - 1));
    if (p1 > 1 && k - p2 > 1)
        kq = max(kq, kt(k - 1, p1 - 1, p2));
    if (p1 > 1 && p2 > 1)
        kq = max(kq, kt(k - 1, p1 - 1, p2 - 1));
    if (p1 == p2)
        kq += a[p1][k - p1];
    else
        kq += a[p1][k - p1] + a[p2][k - p2];

    return dp[k][p1][p2] = kq;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 1; i <= m+n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= m; k++)
                dp[i][j][k] = -1e9;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    cout << kt(m + n, n, m) << "\n";
}
