//https://vn.spoj.com/problems/QBMAX/
#include <bits/stdc++.h>
using namespace std;
int a[101][101];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i <= m; i++)
    {
        a[0][i] = -99999999;
        a[n + 1][i] = -9999999;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int j = 2; j <= m; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            a[i][j] += max(a[i - 1][j - 1], max(a[i][j - 1], a[i + 1][j - 1]));
        }
    }
    int tong     = -9999999;
    for (int i = 1; i <= n; i++)
    {
        tong = max(tong, a[i][m]);
    }
    cout << tong;
    return 0;
}
