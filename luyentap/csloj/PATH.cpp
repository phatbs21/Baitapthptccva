#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> a;
vector<int> d, path;
int m, n, k;
map<pair<int, int>, int> mp;
void dijkstra(int s)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    d[s] = 0;
    q.push({0, s});
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
            if (d[v] < d[u] + w)
            {
                d[v] = d[u] + w;
                q.push({d[v], v});
                
            }
        }
    }
}
int main()
{
    {
    cin >> n >> m >> k;
    a.resize(n);
    for (int i = 0; i < m; i++)
    {
        int tm1, tm2, tm3;
        cin >> tm1 >> tm2 >> tm3;
        a[tm1].push_back({tm2, tm3});
        a[tm2].push_back({tm1, tm2});
    }}
    cout << 3;
}