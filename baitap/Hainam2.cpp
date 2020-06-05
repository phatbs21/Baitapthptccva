#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("test.inp", "r", stdin);
    const int so = 1e7;
    int n, m;
    cin >> n >> m;
    long long int a[n + 1][m + 1], f[300][300];
    f[0][1] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] != -1)
            {
                f[i][j] = (f[i - 1][j] % so + f[i][j - 1] % so) % so;
            }
        }
    }
    long long int tong = f[n][m];
    for (int k = 1; k <= 3; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                f[i][j] = 0;
                if ((a[i][j] == 0) || (a[i][j] == k))
                {
                    f[i][j] = (f[i - 1][j] + f[i][j - 1]);
                }
            }
        }
        tong = tong - f[n][m];
    }
    cout << tong % so;
}
