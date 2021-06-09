#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<long long int, long long int>>> a;
vector<long long int> d, path;
long long int n, t;
#define mm 1000100000
void dijkstra(long long int s)
{
    priority_queue<pair<long long int, long long int>> q;
    path.assign(n + 10, -1);
    d[s] = mm;
    path[s] = s;
    q.push({mm, s});
    while (!q.empty())
    {
        long long int u = q.top().second;
        long long int du = q.top().first;
        q.pop();
        if (du != d[u])
            continue;
        if (u == t)
            break;
        for (long long int i = 0; i < a[u].size(); i++)
        {
            long long int w = a[u][i].second;
            long long int v = a[u][i].first;
            if (d[v] < min(d[u], w))
            {
                d[v] = min(d[u], w);
                q.push({d[v], v});
                path[v] = u;
            }
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("CJDICHUYENLUCLUONG.inp", "r", stdin);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    long long int m, s;
    cin >> n >> m >> s >> t;
    a.resize(n + 10);
    for (long int i = 1; i <= m; i++)
    {
        long long int x, y, z;
        cin >> x >> y >> z;
        a[x].push_back({y, z});
        a[y].push_back({x, z});
    }
    d.assign(n + 10, -1);
    dijkstra(s);
    if (d[t] == mm || d[t] < 1)
        cout << -1;
    else
    {
        cout << d[t] << "\n";
        /*
        stack<long long int> qa;
        qa.push(t);
        while (t != path[t])
        {
            t = path[t];
            qa.push(t);
        }
        while (!qa.empty())
        {
            cout << qa.top() << " ";
            qa.pop();
        }*/
    }
}
/*
10 1 1 5
1 5 7

*/
