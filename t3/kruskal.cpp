#include <bits/stdc++.h>
using namespace std;
map<int, int> cha, hang;
struct edge
{
    int u, v, w;
};
bool cmp(edge x, edge y)
{
    return x.w < y.w;
}
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
    int n, m;
    cin >> n >> m;
    vector<edge> a(m);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i].u >> a[i].v >> a[i].w;
    }
    sort(a.begin(), a.end(), cmp);
    int mst_w = 0;
    for(int i=0;i<=n;i++)
    {
        cha[i]=i;
        hang[i]=0;
    }
    for (int i = 0; i < m; i++)
    {
        if (join(a[i].u, a[i].v))
        {
            mst_w += a[i].w;
        }
    }
    cout << mst_w;
}