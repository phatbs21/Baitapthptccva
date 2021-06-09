#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[501][501], f[501][501];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= n; j++)
            f[i][j] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1] + a[i][j];
        }
    }
    int minn = INT_MAX;
    for (int i = 1; i <= n - 1; i++)
    {
        for (int j = 1; j <= n - 1; j++)
        {
            int ongut = min(min(min(f[i][n] - f[i][j], f[n][j] - f[i][j]), f[n][n] + f[i][j] - f[i][n] - f[n][j]), f[i][j]);
            int ongto = max(max(max(f[i][n] - f[i][j], f[n][j] - f[i][j]), f[n][n] + f[i][j] - f[i][n] - f[n][j]), f[i][j]);
            minn = min(ongto - ongut, minn);
           // cout << ongto << " " << ongut << "\n";
        }
    }
    cout << minn;
}