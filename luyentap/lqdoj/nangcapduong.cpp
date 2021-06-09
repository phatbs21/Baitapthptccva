#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
const int nmax = 1e5 + 1;
int f[nmax], h[nmax], kt[nmax], n, m;
vector<vector<pair<int, int>>> a;
void dijkstra(int s)
{
    priority_queue<ii, vector<ii>, greater<ii>> qq;
    for (int i = 1; i <= n; i++)
    {
        f[i] = 1000000000;
    }
    f[1] = 0;
    qq.push({f[1], 1});
    while (qq.size())
    {
        int u = qq.top().second;
        int du = qq.top().first;
        qq.pop();
        if (f[u] > du)
            continue;
        if (u == n)
            break;
        for (int i = 0; i < a[u].size(); i++)
        {
            int p = a[u][i].second;
            int q = a[u][i].first;
            if (f[p] == q + du)
            {
                h[p] += h[u];
            }
            if (f[p] > q + du)
            {
                f[p] = q + du;
                h[p] = h[u];
                kt[p] = u;
                qq.push({f[p], p});
            }
        }
    }
    int tmp = n, dem = 0, res = 0;
    while (tmp != 1)
    {
        if (h[tmp] != 1)
            res += h[tmp];
        tmp = kt[tmp];
        dem++;
    }
    cout << dem - res;
}
int main()
{
    cin >> n >> m;
    h[1] = 1;
    a.resize(n + 1);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        a[u].push_back({w, v});
        a[v].push_back({w, u});
    }
    dijkstra();
}