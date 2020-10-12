#include <bits/stdc++.h>
using namespace std;
#define N 300300
#define oo 1e9
#define lli long long int
#define NAME "graph"

ifstream fi(NAME ".inp");
ofstream fo(NAME ".out");

#define tocdo cout << "Time " << clock() / (double)1000 << " sec"
vector<lli> adj[N], revadj[N];
vector<lli> a, b;
lli d1[N], dx[N], dy[N];
lli n, m, k;
lli res = 1e9;
void bfs(const vector<lli> &start, vector<lli> adj[], lli d[])
{
    for (lli i = 1; i <= n; ++i)
        d[i] = oo;
    queue<lli> q;
    for (lli x : start)
    {
        d[x] = 0;
        q.push(x);
    }

    while (!q.empty())
    {
        lli u = q.front();
        q.pop();
        for (lli v : adj[u])
        {
            if (d[v] > d[u] + 1)
            {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
}

int main()
{
    fi >> n >> m >> k;
    for (lli i = 1; i <= m; i++)
    {
        lli x;
        fi >> x;
        a.push_back(x);
    }
    for (lli i = 1; i <= k; i++)
    {
        lli x;
        fi >> x;
        b.push_back(x);
    }
    for (lli i = 1; i <= n; i++)
    {
        lli d;
        fi >> d;
        for (lli j = 1; j <= d; j++)
        {
            lli x;
            fi >> x;
            adj[i].push_back(x);
            revadj[x].push_back(i);
        }
    }
    bfs({1}, adj, d1);
    bfs(a, revadj, dx);
    bfs(b, revadj, dy);
    for (lli v = 1; v <= n; v++)
    {
        res = min(res, d1[v] + dx[v] + dy[v]);
    }
    if (res == oo)
        fo << "impossible";
    else
        fo << res;
}