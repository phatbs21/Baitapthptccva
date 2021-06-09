#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> a;
vector<int> d;
int k, n;

void dijkstra(int s)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    d.assign(k + 10, INT_MAX);
    q.push({0, s});
    d[s] = 0;
    while (!q.empty())
    {
        int u = q.top().second;
        int du = q.top().first;
        q.pop();
        if (du != d[u])
            continue;
        for (int i = 0; i < (int)a[u].size(); i++)
        {
            int w = a[u][i].second;
            int v = a[u][i].first;
            int z;
            if (u < v)
            {
                z = du;
                if (z % (w * 2) != 0)
                    z = (z / (w * 2) + 1) * w * 2;
            }
            else
            {
                z = du;
                if (z % 2 * w != w)
                {
                    if (z % (2 * w) < w)
                    {
                        z = z / (2 * w) * (2 * w) + w;
                    }
                    else
                        z = (z / (2 * w) + 1) * 2 * w + w;
                }
            }
            if (z + w < d[v])
            {
                d[v] = z + w;
                q.push({d[v], v});
            }
        }
    }
}
int main()
{
#ifdef LOCAL
    freopen("MELLE3.inp", "r", stdin);
    // freopen("MELLE3.out", "w", stdout);
#endif
    cin >> k >> n;
    a.resize(k + 10);
    for (int i = 0; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        int w = abs(u - v);
        //cin >> w;
        a[u].push_back({v, w});
        a[v].push_back({u, w});
        //  cout << w << endl;
    }
    dijkstra(1);
    cout << d[k] * 5;
}
/*
5 7
1 2 1
2 5 5
2 4 1
1 4 3
4 5 1
1 3 7
3 5 1
*/