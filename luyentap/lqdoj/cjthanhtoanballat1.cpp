#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> a;
vector<int> d, path, visit;
int n;
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    path.assign(n + 10, -1);
    visit.assign(n + 10, false);
    d.assign(n + 10, INT_MAX);
    d[s] = 0;
    visit[s] = true;
    path[s] = s;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < a[u].size(); i++)
        {
            int v = a[u][i];
            //cout << u << " " << v << "\n";
            if (visit[v] != true)
            {
                visit[v] = true;
                d[v] = d[u] + 1;
                path[v] = u;
                q.push(v);
            }
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("cjthanhtoanballat.inp", "r", stdin);
#endif
    int m, s, t;
    cin >> n >> m >> s >> t;
    a.resize(n + 5);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        a[x].push_back(y);
    }
    for(int i=0;i<=n;i++)
    {
        if(a[i].size()>0)
        sort(a[i].begin(),a[i].end());
    }
    bfs(s);
    //cout << d[t] << " ";
    if (d[t] != INT_MAX)
    {
        stack<int> q;
        cout << s << " ";
        while (path[t] != t)
        {
            q.push(t);
            // cout<<1;
            t = path[t];
        }
        while (!q.empty())
        {
            cout << q.top() << " ";
            q.pop();
        }
    }
}