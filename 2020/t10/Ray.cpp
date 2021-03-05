#include <bits/stdc++.h>
using namespace std;
int n, m, dem, soluong, tong = 0, r = -1;
vector<vector<int>> a(251, vector<int>(251));
bool d[251][251], kt = false;
vector<pair<int, int>> q[251];

void floodfill(int x, int y, int prec, int newc)
{
    kt = false;
    if (x <= 0 || y <= 0 || x > n || y > m)
        return;
    if (a[x][y] != prec)
        return;
    dem++;
    a[x][y] = newc;
    floodfill(x, y + 1, prec, newc);
    floodfill(x + 1, y, prec, newc);
    floodfill(x - 1, y, prec, newc);
    floodfill(x, y - 1, prec, newc);
}

void viet(int x, int y, int i)
{
    if (soluong == 0 || a[x][y] != 2 || d[x][y] == true)
        return;
    d[x][y] = true;
    q[i].push_back({x, y});
    soluong--;
    viet(x + 1, y, i);
    viet(x, y + 1, i);
    viet(x - 1, y, i);
    viet(x, y - 1, i);
}

int xuly(int x, int y, int prec, int newc)
{
    dem = 0;
    floodfill(x, y, prec, newc);
    tong += dem;
    return dem;
}
int main()
{
    freopen("ray.inp", "r", stdin);
    freopen("ray.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
        {
            if (a[i][j] != 2 && a[i][j] != 0)
            {
                soluong = xuly(i, j, a[i][j], 2);
                r++;
                viet(i, j, r);
                soluong = 0;
            }
        }
    cout << tong << endl;
    for (int i = 0; i <= r; ++i)
    {
        cout << q[i].size();
        sort(q[i].begin(), q[i].end(), greater<pair<int, int>>());
        while (!q[i].empty())
        {
            cout << " " << q[i].back().first << " " << q[i].back().second;
            q[i].pop_back();
        }
        cout << endl;
    }
}
