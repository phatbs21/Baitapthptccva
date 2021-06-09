#include <bits/stdc++.h>
using namespace std;
vector<int> d, path;
vector<vector<pair<int, int>>> a;

void dijkstra(int s, int c)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    d[s] = 0;
    path[s] = s;
    q.push({0, s});
    while (!q.empty())
    {
        int u = q.top().second;
        int du = q.top().first;
        long long tmp, xx;
        q.pop();
        if (d[u] != du)
        {
            continue;
        }
        for (int i = 0; i < a[u].size(); i++)
            if (a[u][i].second <= c)
            {
                int v = a[u][i].first;
                int l = a[u][i].second;
                if (c - l >= d[u])
                {
                    tmp = d[u] + l;
                    if (d[v] > tmp)
                    {
                        d[v] = tmp;
                        q.push({d[v], v});
                    }
                }
                else if (c > 2 * l)
                {
                    xx = (d[u] + l - c) / (c - 2 * l) - 1;
                    xx = max(xx, (long long)1);
                    for (int j = xx; j <= xx + 10; j++)
                    {
                        tmp = d[u] + l - j * (c - 2 * l);
                        if (tmp >= l && tmp <= c)
                        {
                            tmp = tmp + j * c;
                            if (d[v] > tmp)
                            {
                                d[v] = tmp;
                                q.push({d[v], v});
                            }
                        }
                    }
                }
            }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("NK05DSRT.inp", "r", stdin);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        d.assign(n + 1, INT_MAX);
        path.assign(n + 1, -1);
        a.clear();
        a.resize(n + 1);
        int m, k;
        cin >> m >> k;
        for (int i = 0; i < m; i++)
        {
            int w, b, c;
            cin >> w >> b >> c;
            a[w].push_back({b, c});
            a[b].push_back({w, c});
        }
        dijkstra(1, k);
        cout << d[n] << "\n";
    }
}