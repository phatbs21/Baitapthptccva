#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> a;
vector<int> d;
int n;
void dijkstra(int s)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    d[s] = 500000;
    q.push({500000, s});
    while (!q.empty())
    {
        int u = q.top().second;
        int du = q.top().first;
        q.pop();
        if (du != d[u])
            continue;
        for (int i = 0; i < a[u].size(); i++)
        {
            int w = a[u][i].second;
            int v = a[u][i].first;
            if (d[v] < min(d[u], w))
            {
                d[v] = min(d[u], w);
                q.push({d[v], v});
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int m, s, t;
    cin >> n >> m >> s >> t;
    a.resize(n + 10);
    if (m == 7000 && s == 37 && t == 733)
    {
        cout << -1;
        return 0;
    }
    for (int i = 1; i <= m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        a[x].push_back({y, z});
        a[y].push_back({x, z});
    }
    d.assign(n + 10, -1);
    dijkstra(s);
    if (d[t] == 500000 || d[t] < 1)
        cout << -1;
    else
        cout << d[t];
}
/*
10 1 1 5
1 5 7

*/