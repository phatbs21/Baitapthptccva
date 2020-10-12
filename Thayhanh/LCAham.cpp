// dung de luu tru cac ham LCA
#include <bits/stdc++.h>
using namespace std;
#define NAME "LCA"
#define tocdo cout << "Time " << clock() / (double)1000 << " sec"
#define N 300300
#define LOG 19
ifstream fi(NAME ".inp");
ofstream fo(NAME ".out");
vector<int> adj[N];
int par[N][LOG + 1];
int high[N];
int par[N];
int n;
int dfs(int u)
{
    for (int v : adj[u])
    {
        if (v != par[u])
        {
            par[v] = u;
            high[v] = high[u] + 1;
            dfs(v);
        }
    }
}
int lca(int u, int v)
{
    if (high[u] < high[v])
        return lca(v, u);
    for (int i = LOG; i > 0; i--)
    {
        if (high[par[u][i]] > high[v])
        {
            u = par[u][v];
        }
    }
    if (u == v)
        return u;
    for (int i = LOG; i > 0; i--)
    {
        if (par[u][i] != par[v][i])
        {
            u = par[u][i];
            v = par[v][i];
        }
    }
    return par[u][0];
}
void prepare(void)
{
    dfs(1);
    high[0] = -1;
    for (int j = 1; j <= LOG; j++)
    {
        for (int i = 1; i <= n; i++)
        {
            par[i][j] = par[par[i][j - 1]][j - 1];
        }
    }
}
int lca_slow(int u,int v)
{
    if(high[u]<high[v])
    {
        return lca_slow(v,u);
    }
    while(high[u]>high[v])
    u=par[u];
    while(u!=v)
    {
        u=par[u];
        v=par[v];
    }
    return u;

}
int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        int n;
    }
}