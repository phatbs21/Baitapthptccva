#include <bits/stdc++.h>
using namespace std;
//https://codeforces.com/group/FLVn1Sc504/contest/274827/problem/O
// bo qua chua hoan thanh
//https://vnoi.info/problems/show_solution/PBCPOINT/1387923/
#define oo INT_MAX - 1
#define xx first
#define yy second
vector<pair<int, int>> a;
pair<int, int> u;
map<int, int> miR, miC, maR, maC;
map<pair<int, int>, bool> check;
int n;
void push(int x, int y)
{
    check[{x, y}] = true;
    n++;
    a[n].xx = x;
    a[n].yy = y;
    miR[x] = min(miR[x], y);
    maR[x] = max(maR[x], y);
    miC[y] = min(miC[y], x);
    maC[y] = max(maC[y], x);
}
int main()
{
#ifdef LOCAL
    freopen("PBCPOINT.inp", "r", stdin);
#endif
    cin >> n;
    int minx = INT_MAX, miny = INT_MAX, maxx = INT_MIN, maxy = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        a.push_back({x, y});
        minx = min(minx, x);
        miny = min(miny, y);
        maxx = max(x, maxx);
        maxy = max(y, maxy);
    }
    for (int i = minx; i <= maxx; i++)
        miR[i] = oo;
    for (int i = miny; i <= maxy; i++)
        miC[i] = oo;
    for (int i = minx; i <= maxx; i++)
        maR[i] = -oo;
    for (int i = miny; i <= maxy; i++)
        maR[i] = -oo;
    for (int i = 1; i <= n; i++)
    {
        int x = a[i].xx;
        int y = a[i].yy;
        miR[x] = min(miR[x], y);
        maR[x] = max(maR[x], y);
        miC[y] = min(miC[y], x);
        maC[y] = max(maC[y], x);
    } // R = x, C = y
    int l = 0, r = n - 1;
    while (l <= r)
    {
        u.xx = a[l].xx;
        u.yy = a[l].yy;
        l++;
        if (u.xx == miC[u.yy] || u.xx == maC[u.yy])
        {
            for (int x = miC[u.yy]; x <= maC[u.yy]; x++)
            {
                if (check[{x, u.yy}] == false)
                {
                    push(x, u.yy);
                }
            }
        }
        if (u.yy == miR[u.xx] || u.yy == maR[u.xx])
        {
            for (int y = miR[u.xx]; y <= maR[u.xx]; y++)
            {
                if (check[{u.xx, y}] == false)
                {
                    push(u.xx, y);
                }
            }
        }
    }
    int dem = 0;
    for (int i = minx; i <= maxx; i++)
        for (int j = miny; i <= maxy; i++)
            if (check[{i, j}] == true)
                dem++;
    cout << dem;
}
