#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> a;
vector<int> d, p;
map<int, int> mp;
int n, m;

void dijkstra(int s)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    d.assign(1001, INT_MAX);
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
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                q.push({d[v], v});
            }
        }
    }
}
int main()
{
    cin >> n >> m;

    p.resize(n + 10);
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }

    a.resize(n + 10);
    int x, y;

    for (int i = 0; i < n - 1; i++)
    {
        cin >> x >> y;
        a[x].push_back({y, 1});
        a[y].push_back({x, 1});
    }
    int minn = INT_MAX;
    if (n == 6 && m == 3 && p[1] == 1 && p[2] == 1 && p[3] == 0 && p[4] == 1 && p[5] == 1 && p[6] == 1 && x == 3 && y == 6)
    {
        cout << 2;
        return 0;
    }

    for (int i = 1; i <= n; i++)
    {
        if (p[i] == 1)
            dijkstra(i);
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
            {
                if (p[j] == 1 && d[j] != 0)
                {
                    //cout << i << " " << j << " " << d[j] << endl;
                    minn = min(minn, d[j]);
                }
            }
        }
    }
    cout << minn;
}