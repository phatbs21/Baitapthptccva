#include <bits/stdc++.h>
using namespace std;
int d[101][101], n, yo, xo;
bool kt = false;
queue<pair<int, int>> q;
pair<int, int> kq[101], u;
void lannguoc()
{
    int x = xo;
    int b, k = 0;
    int y = yo;
    while (x > 0 && y > 0)
    {
        kq[k] = make_pair(x, y);
        ++k;
        b = d[x][y] - 1;
        if (d[x - 1][y - 2] == b && y > 2)
        {
            x -= 1;
            y -= 2;
            continue;
        }
        if (d[x - 1][y + 2] == b)
        {
            x -= 1;
            y += 2;
            continue;
        }
        if (d[x + 1][y - 2] == b && y > 2)
        {
            x += 1;
            y -= 2;
            continue;
        }
        if (d[x + 1][y + 2] == b)
        {
            x += 1;
            y += 2;
            continue;
        }
        if (d[x - 2][y - 1] == b && x > 2)
        {
            x -= 2;
            y -= 1;
            continue;
        }
        if (d[x - 2][y + 1] == b && x > 2)
        {
            x -= 2;
            y += 1;
            continue;
        }
        if (d[x + 2][y - 1] == b)
        {
            x += 2;
            y -= 1;
            continue;
        }
        if (d[x + 2][y + 1] == b)
        {
            x += 2;
            y += 1;
            continue;
        }
    }
    //cout << "1 1" << endl;
    --k;
    while (k >= 0)
    {
        cout << kq[k].first << " " << kq[k].second << endl;
        --k;
    }
}
void themo(int ox, int oy, int k)
{
    if (ox >= 1 && ox <= n && oy >= 1 && oy <= n && d[ox][oy]==-1)
    {
        d[ox][oy] = k;
        q.push(make_pair(ox, oy));
        if (ox == xo && oy == yo)
        {
            lannguoc();
            kt = true;
        }
    }
    return;
}
void setmang()
{
    for (int i = 0; i <= 100; ++i)
        for (int j = 0; j <= 100; ++j)
            d[i][j] = -1;
    d[1][1] = 0;
    return;
}
int main()
{
    //freopen("quanma.inp", "r", stdin);
    freopen("quanma.out", "w", stdout);
    setmang();
    int b;
    q.push(make_pair(1, 1));
    cin >> n >> xo >> yo;
    //cout << n << xo << yo;
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        b = d[u.first][u.second] + 1;
        themo(u.first - 1, u.second - 2, b);
        if (kt == true)
            continue;
        themo(u.first - 1, u.second + 2, b);
        if (kt == true)
            continue;
        themo(u.first - 2, u.second - 1, b);
        if (kt == true)
            continue;
        themo(u.first - 2, u.second + 1, b);
        if (kt == true)
            continue;
        themo(u.first + 2, u.second - 1, b);
        if (kt == true)
            continue;
        themo(u.first + 2, u.second + 1, b);
        if (kt == true)
            continue;
        themo(u.first + 1, u.second - 2, b);
        if (kt == true)
            continue;
        themo(u.first + 1, u.second + 2, b);
        if (kt == true)
            continue;
    }
}