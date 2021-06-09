#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<long long int, long long int>>> a;
vector<long long int> d, path;
long long int n;
void dijkstra(long long int s)
{
    priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, greater<pair<long long int, long long int>>> q;
    d.assign(500001, INT_MAX);
    path.assign(n + 10, -1);
    d[s] = 0;
    path[s] = s;
    q.push({0, s});
    while (!q.empty())
    {
        long long int u = q.top().second;
        long long int du = q.top().first;
        q.pop();
        if (d[u] != du)
        {
            continue;
        }
        for (long long int i = 0; i < a[u].size(); i++)
        {
            long long int v = a[u][i].first;
            long long int w = a[u][i].second;
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
    long long int m, s, t;
    cin >> n >> m >> s >> t;
    a.resize(500001);
    for (long long int i = 1; i <= m; i++)
    {
        long long int x, y, c;
        cin >> x >> y >> c;
        a[x].push_back({y, c});
        a[y].push_back({x, c});
    }
    dijkstra(s);
    if (d[t] != INT_MAX)
    {
        cout << d[t] << "\n";
        stack<long long int> q;
        q.push(t);
        long long int w = t;
        while (path[w] != w)
        {
            w = path[w];
            q.push(w);
        }
        while (!q.empty())
        {
            cout << q.top() << " ";
            q.pop();
        }
    }
}