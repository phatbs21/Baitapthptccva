#include <bits/stdc++.h>
#define NAME "microbus"
using namespace std;
ifstream fi(NAME ".inp");
ofstream fo(NAME ".out");
int main()
{
    int m, n, p, q;
    fi >> n >> m >> p >> q;

    vector<int> a(n), b(n);
    vector<vector<int>> dp(n + 1, vector<int>(m + 1));
    for (int i = 0; i < n; i++)
    {
        fi >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        fi >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
        dp[i][0] = p * i;
    for (int i = 1; i <= m; i++)
        dp[0][i] = q * i;

    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
        {
            dp[i][j] = min(min(dp[i - 1][j] + p,
                               dp[i][j - 1] + q),
                           dp[i - 1][j - 1] + abs(a[i] - b[j]));
        }
    fo << dp[n][m];
}