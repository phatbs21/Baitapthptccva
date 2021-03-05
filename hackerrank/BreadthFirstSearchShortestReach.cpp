#include <bits/stdc++.h>
using namespace std;
vector<int> a[10000];
void Bfs(int n, int s)
{
    vector<bool> visit(n, false);
    vector<int> path(n, -1);
    queue<int> q;
    vector<int> sum(n, 0);
    q.push(s);
    visit[s] = true;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < a[u].size(); i++)
        {
            int v = a[u][i];
            if (!visit[v])
            {
                sum[v] = 6 + sum[u];
                visit[v] = true;
                q.push(v);
                path[v] = u;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == s)
            continue;
        if (sum[i] != 0)
        {
            cout << sum[i] << " ";
        }
        else
            cout << -1 << " ";
    }
    cout << "\n";
}
int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int n, m, s;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            a[i].clear();
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            x--;
            y--;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        cin >> s;
        s--;
        Bfs(n, s);
    }
}