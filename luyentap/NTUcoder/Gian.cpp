#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n, a[1000][1000];
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> m >> n;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            a[i][j] = a[i][j] + max(a[i - 1][j], a[i][j - 1]);
        }
    }
    cout << a[m][n];
}