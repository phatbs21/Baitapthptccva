#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> a;
vector<int> d, path;
int n;
// chua ra
void dijkstra(int s)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    d.assign(n + 1, INT_MAX);
    path.assign(n + 1, -1);
    d[s] = 0;
    path[s] = s;
    q.push({0, s});
    while (!q.empty())
    {
        int u = q.top().second;
        int du = q.top().first;
        q.pop();
        if (d[u] != du)
        {
            continue;
        }
        for (int i = 0; i < a[u].size(); i++)
        {
            int v = a[u][i].first;
            int w = a[u][i].second;
            if (d[u] + w < d[v])
            {
                d[v] = d[u] + w;
                q.push({d[v], v});
                path[v] = u;
            }
        }
    }
}
int main()
{
    int m;
    cin >> n >> m;
    a.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int k, u, v, l;
        cin >> k >> u >> v >> l;
        if (k == 1)
        {
            a[u].push_back({v, l});
        }
        else
        {
            a[u].push_back({v, l});
            a[v].push_back({u, l});
        }
    }
    vector<int> luu;
    dijkstra(1);
    cout << d[n];
}