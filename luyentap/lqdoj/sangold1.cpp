#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
vector<vector<int>> a, b;
int c[500][500];
long long int kq = 0;
vector<int> xx{0, 0, 1, -1}, yy{1, -1, 0, 0};
int n, m, kqq = 0;
int xxx, yyy, zzz;
long long int l, r;
void loang(int u, int v, int w)
{
    c[u][v] = 1;
    kq += b[u][v];
    for (int i = 0; i < 4; i++)
    {
        int x = u + xx[i];
        int y = v + yy[i];
        if (x < 0 || y < 0 || x > n - 1 || y > m - 1)
            continue;
        if (c[x][y] == 1 || abs(a[x][y] - a[u][v]) > w)
            continue;
        loang(x, y, w);
    }
    return;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    a.assign(n, vector<int>(m));
    b.assign(n, vector<int>(m, 0));
    // c.assign(n + 1, vector<int>(m + 1));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> b[i][j];
            if (b[i][j] == 1)
            {
                xxx = i, yyy = j, zzz++;
            }
        }

    l = 0, r = 1e9;
    while (l <= r)
    {

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
                c[i][j] = 0;
        }
        kq = 0;
        int m2 = (l + r) / 2;
        loang(xxx, yyy, m2);
        if (kq != zzz)
            l = m2 + 1;
        else
        {
            r = m2 - 1;
            kqq = m2;
        }
    }
    cout << kqq;
}