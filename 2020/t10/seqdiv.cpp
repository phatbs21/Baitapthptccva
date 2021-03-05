#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("seqdiv.inp", "r", stdin);
    freopen("seqdiv.out", "w", stdout);
    long long int MOD = 1000000000 + 7;
    long long int MAX = 20000;
    long long int n, m;
    cin >> n >> m;
    long long int dp[101][MAX];
    vector<long long int> boi[MAX], uoc[MAX];
    memset(dp, 0, sizeof(dp));
    memset(boi, 0, sizeof(boi));
    memset(uoc, 0, sizeof(uoc));
    for (long long int i = 1; i <= m; i++)
    {
        for (long long int j = 2 * i; j <= m; j += i)
        {
            boi[j].push_back(i);
            uoc[i].push_back(j);
        }
    }
    for (long long int i = 1; i <= m; i++)
        dp[1][i] = 1;
    for (long long int i = 2; i <= n; i++)
    {
        for (long long int j = 1; j <= m; j++)
        {
            dp[i][j] = 0;
            for (long long int k = 0; k < boi[j].size(); k++)
            {
                dp[i][j] += dp[i - 1][boi[j][k]] % MOD;
            }
            for (long long int k = 0; k < uoc[j].size(); k++)
            {
                dp[i][j] += dp[i - 1][uoc[j][k]] % MOD;
            }
            //cout << dp[i][j] << " " << i << " " << j << " "
        }
    }
    dp[0][0] = 0;
    for (long long int i = 1; i <= m; i++)
    {
        dp[0][0] += dp[n][i] % MOD;
    }
    cout << dp[0][0] % MOD;
}
