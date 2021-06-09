//https://codeforces.com/group/FLVn1Sc504/contest/274809/problem/M
#include <bits/stdc++.h>
using namespace std;
struct edge
{
    int u, v, w;
};
int hang[100009], cha[100009];
int dem = 0;
bool cmp(edge x, edge y)
{
    return x.w < y.w;
}
int find(int u)
{
    if (cha[u] == u)
        return u;
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
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;
    vector<int> c(n + 1);
    vector<edge> a(m);
    int mst_w = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
        mst_w = min(mst_w, c[i]);
    }
    for (int i = 0; i < m; i++)
    {
        int w;
        cin >> a[i].u >> a[i].v >> w;
        a[i].w = w * 2 + c[a[i].u] + c[a[i].v];
    }
    for (int i = 1; i <= n; i++)
    {
        hang[i] = 0;
        cha[i] = i;
    }
    sort(a.begin(), a.end(), cmp);
    int dem = 0;
    for (int i = 0; i < m; i++)
    {
        if (dem == n - 1)
            break;
        if (join(a[i].u, a[i].v))
        {
            mst_w += a[i].w;
            dem++;
        }
    }
    cout << mst_w;
}