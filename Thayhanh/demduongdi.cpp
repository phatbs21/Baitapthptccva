#include <bits/stdc++.h>
using namespace std;
#define N 3000005
#define NAME "demduongdi"
#define tocdo cout << "Time " << clock() / (double)1000 << " sec"
ifstream fi(NAME ".inp");
ofstream fo(NAME ".out");

int n, p, u, v;
vector<int> adj[300005];
int fin[300005][30], fout[300005][30];
void dfsOne(int u, int par)
{
    fin[u][0] = 1;
    for (int v : adj[u])
    {
        if (v != par)
        {
            dfsOne(v, u);
            for (int i = 0; i < p; i++)
                fin[u][(i + 1) % p] += fin[v][i];
        }
    }
}
void dfsTwo(int u, int par)
{
    int sum[30];
    memset(sum, 0, sizeof sum);
    for (int v : adj[u])
    {
        if (v != par)
        {
            for (int i = 0; i < p; i++)
                sum[i] += fin[v][i];
        }
    }
    for (int v : adj[u])
    {
        if (v != par)
        {
            for (int i = 0; i < p; i++)
            {
                fout[v][(i + 1) % p] += fout[u][i];
                fout[v][(i + 2) % p] += sum[i] - fin[v][i];
            }
            if (p == 1)
                fout[v][0]++;
            else
                fout[v][1]++;
            dfsTwo(v, u);
        }
    }
}
int main()
{
    fi >> n >> p;
    for (int i = 0; i < n - 1; i++)
    {
        fi >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfsOne(1, -1);
    dfsTwo(1, -1);
    for (int i = 1; i <= n; i++)
    {
        fo << fin[i][0] + fout[i][0] << " ";
    }
}