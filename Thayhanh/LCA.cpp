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
int n;
int dfs(int u)
{
    for (int v : adj[u])
    {
        if (v != par[u][0])
        {
            par[v][0] = u;
            high[v] = high[u] + 1;
            dfs(v);
        }
    }
}
int lca(int u, int v)
{
    if (high[u] < high[v])
        return lca(v, u);
    for (int i = LOG; i >= 0; i--)
    {
        if (high[par[u][i]] >= high[v])
        {
            u = par[u][i];
        }
    }
    if (u == v)
        return u;
    for (int i = LOG; i >= 0; i--)
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

int main()
{
    int test;
    fi >> test;
    for (int t = 1; t <= test; t++)
    {
        memset(high, 0, sizeof(high));
        memset(adj, 0, sizeof(adj));
        memset(par, 0, sizeof(par));
        int q;
        fi >> n;
        for (int i = 1; i <= n; i++)
        {
            int temp;
            fi >> temp;
            for (int j = 1; j <= temp; j++)
            {
                int z = 0;
                fi >> z;
                adj[i].push_back(z);
            }
        }
        prepare();
        fi >> q;
        cout << "Case " << t << ":\n";
        for (int i = 0; i < q; i++)
        {
            int v, w;
            fi >> v >> w;
            cout << lca(v, w) << "\n";
        }
    }
}