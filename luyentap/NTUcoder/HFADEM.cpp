#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> a;
int n, m, k;
vector<int> kq;
void bfs(int s)
{
    vector<bool> visit(n, false);
    vector<int> path(n, -1);
    queue<int> q;
    vector<int> duong(n, 1);
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
                duong[v]++;
                visit[v] = true;
                q.push(v);
                path[v] = u;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (path[i] != 1)
        {
            if (duong[i] >= k)
                kq.push_back(i);
        }
    }
}
int main()
{
    cin >> n >> m >> k;
    a.resize(n);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    int Max = 0;
    for (int i = 0; i < n; i++)
    {
        kq.clear();
        bfs(i);
        if (kq.size() > Max)
            Max = kq.size();
    }
    for (int i = 0; i < n; i++)
    {
        kq.clear();
        bfs(i);
        if (Max == kq.size())
        {
            cout << kq.size() << "\n";
            for (int i = 0; i < kq.size(); i++)
                cout << kq[i] << " ";
            return 0;
        }
    }
}