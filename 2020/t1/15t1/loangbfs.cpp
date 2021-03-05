#include <bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
bool d[1000][1000];
int v, s, smax = 0, n, a[1000][1000], m;
queue<pii> q;

void loang(int x, int y)
{
    int g;
    q.push(make_pair(x, y));
    d[x][y] = true;
    static pair<int, int> u;
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        g = a[u.first][u.second];
        if (a[u.first - 1][u.second] == g && d[u.first - 1][u.second] == false)
        {
            q.push(make_pair(u.first - 1, u.second));
            d[u.first - 1][u.second] = true;
        }
        if (a[u.first][u.second + 1] == g && d[u.first][u.second + 1] == false)
        {
            q.push(make_pair(u.first, u.second + 1));
            d[u.first][u.second + 1] = true;
        }
        if (a[u.first + 1][u.second] == g && d[u.first + 1][u.second] == false)
        {
            q.push(make_pair(u.first + 1, u.second));
            d[u.first + 1][u.second] = true;
        }
        if (a[u.first][u.second - 1] == g && d[u.first][u.second - 1] == false)
        {
            q.push(make_pair(u.first, u.second - 1));
            d[u.first][u.second - 1] = true;
        }
        s++;
    }
}
int main()
{
    freopen("loang.inp", "r", stdin);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
            d[i][j]=false;
        }
    }
    v = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (d[i][j] == false)
            {
                v++;
                s = 0;
                loang(i, j);
                if (s > smax)
                {
                    smax = s;
                }
            }
        }
    }
    cout << v << " " << smax;
}