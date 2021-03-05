#include <bits/stdc++.h>
using namespace std;
int N, T, v;
vector<int> w, t, kq;
vector<vector<int>> a;
int Max = 0;
void bfs(int s)
{
    vector<bool> visit(N, false);
    vector<vector<int>> sum(N, vector<int>(N, 0));
    queue<int> q;
    q.push(s);
    visit[s] = true;
    while (!q.empty())
    {
        int u = q.front();
        sum[u][u] = w[u];
        q.pop();
        for (int i = 0; i < a[u].size(); i++)
        {
            int v = a[u][i];
            if (!visit[v])
            {
                sum[u][v] += w[v];
                visit[v] = true;
                q.push(v);
            }
        }
    }
    visit[s] = true;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            cout << sum[i][j] << " ";
        }
    }
}
int main()
{
    freopen("dulich.inp", "r", stdin);
    cin >> N >> T >> v;
    t.resize(N);
    for (auto &i : t)
        cin >> i;
    a.resize(N);
    int z, x, c;
    while (cin >> z >> x >> c)
    {
        z--;
        x--;
        w.push_back(c);
        a[z].push_back(x);
        a[x].push_back(z);
    }
    int q = w.size();
    for (int i = 0; i < N; i++)
    {
        bfs(i);
    }
}