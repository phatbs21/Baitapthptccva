#include <bits/stdc++.h>
using namespace std;
int n, m, s, e;
vector<bool> visit;
vector<vector<int>> a;
vector<int> minPath;
void dijkstra()
{
    int u;
    do
    {
        u = e;
        for (int i = 1; i <= n; i++)
        {
            if (visit[i] == false && minPath[u] > minPath[i])
                u = i;
        }
        visit[u] = true;
        if (minPath[u] == INT_MAX || u == e)
        {
            break;
        }
        for (int v = 1; v <= n; v++)
        {
            if (a[u][v] > 0 && !visit[v])
            {
                if ((a[u][v] + minPath[u]) < minPath[v])
                {
                    minPath[v] = a[u][v] + minPath[u];
                }
            }
        }
    } while (true);
}

int main()
{
    //freopen("dijkstrashortreach.inp", "r", stdin);
    //freopen("dijkstrashortreach.out", "w", stdout);
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        e = n;
        a.resize(n + 1);
        for (int i = 1; i <= n; i++)
            a[i].assign(n + 1, 0);
        visit.assign(n + 1, false);
        minPath.assign(n + 1, INT_MAX);
        vector<vector<int>> check(n + 2, vector<int>(n + 2, 0));
        for (int i = 1; i <= m; i++)
        {
            int u, v, weigh;
            cin >> u >> v >> weigh;
            if (check[u][v] == 1)
            {
                if (weigh < a[u][v])
                {
                    a[u][v] = weigh;
                    a[v][u] = weigh;
                }
            }
            else
            {
                check[u][v] = 1;
                a[u][v] = weigh;
                a[v][u] = weigh;
            }
        }
        cin >> s;
        minPath[s] = 0;
        dijkstra();
        for (int i = 1; i <= n; i++)
        {
            if (i != s && minPath[i] != 0)
            {
                if (minPath[i] == INT_MAX)
                    cout << "-1 ";
                else
                    cout << minPath[i] << " ";
            }
        }
        cout << "\n";
    }
}