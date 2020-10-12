#include <bits/stdc++.h>
using namespace std;
const int N = 3000;
int n;
int f[N][N], a[N], s[N][N];
int main()
{
    freopen("OPTCUT.inp", "r", stdin);
    freopen("OPTCUT.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        s[i][i] = i;
    }
    for (int j = 2; j <= n; j++)
        for (int i = j - 1; i > 0; i--)
        {
            f[i][j] = INT_MAX;
            for (int k = s[i][j - 1]; k <= s[i + 1][j]; k++)
            {
                if (f[i][k] + f[k + 1][j] + a[j] - a[i - 1] < f[i][j])
                {
                    f[i][j] = f[i][k] + f[k + 1][j] + a[j] - a[i - 1];
                    s[i][j] = k;
                }
            }
        }
    cout << f[1][n];
}