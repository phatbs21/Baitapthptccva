#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define iii pair<int, pair<int, int>>

int n, m, k, a[1009][1009], b[1009][1009], d[1009][1009];
int h1, g1, h2, g2;
int loang1[] = {0, -1, 0, 1};
int loang2[] = {-1, 0, 1, 0};
vector<pair<int, int>> vt;
bool check(int t)
{
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            b[i][j] = d[i][j] = 0;
    queue<pair<int, int>> Q;
    for (int i = 0; i < vt.size(); i++)
    {
        Q.push(vt[i]);
        b[vt[i].first][vt[i].second] = 1;
    }
    while (!Q.empty())
    {
        int u = Q.front().first;
        int v = Q.front().second;
        Q.pop();
        if (b[u][v] >= t)
            break;
        for (int i = 0; i <= 3; i++)
        {
            int x = u + loang1[i];
            int y = v + loang2[i];
            if (x < 1 || x > n || y < 1 || y > m)
                continue;
            if (b[x][y])
                continue;
            if (a[x][y])
                continue;
            b[x][y] = b[u][v] + 1;
            Q.push({x, y});
        }
    }
    priority_queue<iii, vector<iii>, greater<iii>> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            d[i][j] = 1e9;
    d[h1][h2] = 0;
    q.push({0, {h1, h2}});
    while (!q.empty())
    {
        int w = q.top().first;
        int u = q.top().second.first;
        int v = q.top().second.second;
        q.pop();
        if (d[u][v] < w)
            continue;
        for (int i = 0; i <= 3; i++)
        {
            int x = u + loang1[i];
            int y = v + loang2[i];
            if (x < 1 || x > n || y < 1 || y > m)
                continue;
            int c = (b[x][y] != 0);
            if (d[x][y] > w + c && w + c <= k)
            {
                d[x][y] = w + c;
                q.push({d[x][y], {x, y}});
            }
        }
    }
    return (d[g1][g2] <= k);
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        string s;
        cin >> s;
        for (int j = 1; j <= m; j++)
        {
            if (s[j - 1] == '.')
                a[i][j] = 0;
            if (s[j - 1] == 'H')
                a[i][j] = 1;
            if (s[j - 1] == 'G')
                a[i][j] = 2;
            if (s[j - 1] == 'S')
                a[i][j] = 3;
        }
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i][j] == 1)
                h1 = i,
                h2 = j;
            else if (a[i][j] == 2)
                g1 = i,
                g2 = j;
            else if (a[i][j] == 3)
                vt.push_back({i, j});
    int l = 0, r = n + m;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
            l = mid + 1;
        else
            r = mid - 1;
    }
    if (r != n + m)
        cout << r;
    else
        cout << -1;
}
