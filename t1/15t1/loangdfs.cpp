#include <bits/stdc++.h>
using namespace std;
int s = 0;
int a[10000][10000];
int loang(int x, int y)
{
    s++;
    int g = a[x][y];
    a[x][y] = 0;
    if (a[x - 1][y] == g)
        loang(x - 1, y);
    if (a[x][y + 1] == g)
        loang(x, y + 1);
    if (a[x + 1][y] == g)
        loang(x + 1, y);
    if (a[x][y - 1] == g)
        loang(x, y - 1);
}
int main()
{
    freopen("loang.inp", "r", stdin);
    int m, n;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    int v = 0, Smax = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] > 0)
            {
                v++;
                s = 0;
                loang(i, j);
                if (s > Smax)
                {
                    Smax = s;
                }
            }
        }
    }
    cout << v << " " << Smax;
}