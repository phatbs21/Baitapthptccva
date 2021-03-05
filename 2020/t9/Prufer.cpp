#include <bits/stdc++.h>
using namespace std;
ifstream fi("prufer.inp");
ofstream fo("prufer.out");
const int MAXN = 100001;
int n, a, b;
vector<int> g[MAXN];
int degree[MAXN];
bool killed[MAXN];
vector<int> prufer_code()
{
    set<int> leaves;
    for (int i = 0; i < n; ++i)
    {
        degree[i] = (int)g[i].size();
        if (degree[i] == 1)
            leaves.insert(i);
        killed[i] = false;
    }
    vector<int> result(n - 2);
    for (int iter = 0; iter < n - 2; ++iter)
    {
        int leaf = *leaves.begin();
        leaves.erase(leaves.begin());
        killed[leaf] = true;
        int v;
        for (size_t i = 0; i < g[leaf].size(); ++i)
            if (!killed[g[leaf][i]])
                v = g[leaf][i];
        result[iter] = v;
        if (--degree[v] == 1)
            leaves.insert(v);
    }
    return result;
}
int main()
{
    fi >> n;
    for (int i = 0; i < n - 1; ++i)
    {
        fi >> a >> b;
        --a;
        --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    vector<int> ans(n - 2);
    ans = prufer_code();
    for (int i : ans)
        fo << i + 1 << ' ';
}