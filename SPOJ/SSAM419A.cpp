#include <bits/stdc++.h>
using namespace std;
#define NAME "SSAM419A"
#define tocdo fo << "Time " << clock() / (double)1000 << " sec"
ifstream fi(NAME ".inp");
ofstream fo(NAME ".out");

//#define fi cin
//#define fo cout
const int N = 100001;
vector<int> g[N];
vector<bool> used;
vector<int> thutu;
void dfs(int u)
{
    thutu.push_back(u);
    used[u] = true;
    for (auto &v : g[u])
    {
        if (used[v] == false)
            dfs(v);
    }
    used[u] = true;
}

int main()
{
    int t;
    fi >> t;
    while (t--)
    {
        thutu.clear();
        used.assign(N, false);
        g->clear();
        int n, m, u;
        fi >> n >> m >> u;
        for (int j = 0; j < m; j++)
        {
            int temp1, temp2;
            fi >> temp1 >> temp2;
            temp1--;
            temp2--;
            g[temp1].push_back(temp2);
            g[temp2].push_back(temp1);
        }
        dfs(u - 1);
        for (auto i : thutu)
            fo << i + 1 << " ";
        fo << "\n";
    }
}