#include <bits/stdc++.h>
using namespace std;
const int MaxN = 2001;
typedef pair<int, int> ii;
struct node
{
    int u, w;
    double c;
    node(int _u, int _w, double _c)
    {
        u = _u;
        w = _w;
        c = _c;
    }
    bool operator<(const node &other) const
    {
        return c > other.c;
    }
};

#define fi first
#define se second

int n, m, k, ok[201][21];
double d[100][21];
vector<ii> a[200];

void dijkstra()
{
    for (int i = 2; i <= n; ++i)
        for (int j = 0; j <= k; ++j)
            d[i][j] = 1e9 + 777;
    priority_queue<node> q;
    for (int i = 0; i <= k; ++i)
        q.push(node(1, i, d[1][i]));
    while (!q.empty())
    {
        int u = q.top().u, w = q.top().w;
        double du = q.top().c;
        q.pop();
        ok[u][w] = 1;
        if (d[u][w] != du)
            continue;
        if (u == n && w == k)
            break;
        for (int i = 0; i < a[u].size(); i++)
        {
            int v = a[u][i].se;
            double dv = a[u][i].fi;
            int c = 1;
            for (int j = w; j <= k; ++j)
            {
                if (!ok[v][j] && d[v][j] > d[u][w] + dv / c)
                {
                    d[v][j] = d[u][w] + dv / c;
                    q.push(node(v, j, d[v][j]));
                }
                c = c * 2;
            }
        }
    }
}

int main()
{
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        a[u].push_back({c, v});
        a[v].push_back({c, u});
    }
    dijkstra();
    cout << fixed << setprecision(2) << d[n][k];
}