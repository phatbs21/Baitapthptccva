#include <bits/stdc++.h>
using namespace std;
bool d[100][100];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}, a[100][100];
int s = 0, Smin = 1, x2, y2;
void den(int x, int y)
{
    if (x == x2 && y == y2)
    {
        if (s < Smin)
            Smin = s;
    }
    else
    {
        for (int i = 0; i < 4; i++)
        {
            if (d[x + dx[i]][y + dy[i]] == false)
            {
                s += a[x + dx[i]][y + dy[i]];
                d[x + dx[i]][y + dy[i]] = true;
                den(x + dx[i], y + dy[i]);
                d[x + dx[i]][y + dy[i]] = false;
                s -= a[x + dx[i]][y + dy[i]];
            }
        }
    }
}
int main()
{
    freopen("test.inp", "r", stdin);
    int m, n;
    cin >> m >> n >> x2 >> y2;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            Smin += a[i][j];
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            d[i][j] = false;
        }
        d[i][0] = true;
        d[i][n + 1] = true;
    }
    s += a[4][2];
    for (int j = 1; j <= n; j++)
        d[0][j] = d[m + 1][j] = true;
    den(4, 2);
    cout << Smin << endl;
    return 0;
}
