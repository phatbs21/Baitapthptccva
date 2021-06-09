#include <bits/stdc++.h>
using namespace std;
const int N = 10000;
vector<vector<int>> g;
vector<bool> used;
vector<int> time_in, time_out;
int dem = 0;
void dfs(int u)
{
    cout << u << " ";
    time_in[u] = dem++;
    used[u] = true;
    for (auto &v : g[u])
    {
        if (!used[v])
            dfs(v);
    }
    time_out[u] = dem++;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("dfs.inp", "r", stdin);
    //freopen("dfs.out","w",stdout);
    int n, t; //n: dinh, t : nhap dinh
    cin >> n >> t;
    g.resize(n);
    used.resize(n);
    time_in.resize(n);
    time_out.resize(n);
    for (int i = 0; i < t; i++)
    {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(0);
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << time_in[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << time_out[i] << " ";
    }
}