#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int dbrr = 202, MOD = 1e9 + 7;
int n, m, a[dbrr][dbrr], dp[2 * dbrr][dbrr][dbrr];

int main()
{
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= m + n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= m; k++)
                dp[i][j][k] = -1e9;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
}
