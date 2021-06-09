#include <bits/stdc++.h>
using namespace std;
#define NAME "T_IN_OUT"
ifstream fi(NAME ".inp");
ofstream fo(NAME ".out");
const int N = 300005;
vector<int> g[N];
vector<int> time_in(N), time_out(N);
int n;
int time_dfs = 0;
void wtr()
{
    fo << "T... in/out:" << endl;
    for (int i = 0; i < n; ++i)
        fo << time_in[i] << ' ';
    fo << endl;
    for (int i = 0; i < n; ++i)
        fo << time_out[i] << ' ';
    fo << endl;
}

void dfs(int u, int y)
{
    time_in[u] = time_dfs++;
    for (auto v : g[u])
    {
        if (v != y)
            dfs(v, u);
    }
    time_out[u] = time_dfs;
}
int main()
{
    fi >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        fi >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(0, 0);
    wtr();
}