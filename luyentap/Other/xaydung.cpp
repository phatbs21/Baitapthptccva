#include <bits/stdc++.h>
using namespace std;
struct edge
{
    int u, v, w;
};
bool cmp(const edge &a, const edge &b)
{
    return a.w < b.w;
}
#define N 10005
int cha[N], hang[N];
int find(int u)
{
    if (cha[u] != u)
        cha[u] = find(cha[u]);
    return cha[u];
}
bool join(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v)
        return false;
    if (hang[u] == hang[v])
        hang[u]++;
    if (hang[u] < hang[v])
        cha[u] = v;
    else
        cha[v] = u;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<edge> edges(m);
    for (edge &e : edges)
        cin >> e.u >> e.v >> e.w;
    sort(edges.begin(), edges.end(), cmp);
    for (int i = 1; i <= n; i++)
    {
        cha[i] = i;
        hang[i] = 0;
    }
    int mst_weight = 0;
    for (edge &e : edges)
    {
        if (join(e.u, e.v))
        {
            mst_weight ++;
        }
    }
    cout << mst_weight;
    return 0;
}
