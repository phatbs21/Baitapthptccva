#include <bits/stdc++.h>
using namespace std;
ifstream fi("prufertt.inp");
ofstream fo("prufertt.out");
const int MAXN = 100001;
int n, a, b;
vector<int> g[MAXN];
int degree[MAXN], parent[MAXN];
void dfs(int v)
{
    for (size_t i = 0; i < g[v].size(); ++i)
    {
        int to = g[v][i];
        if (to != parent[v])
        {
            parent[to] = v;
            dfs(to);
        }
    }
}
vector<int> prufer_code()
{
    parent[n - 1] = -1;
    dfs(n - 1);
    int ptr = -1;
    for (int i = 0; i < n; ++i)
    {
        degree[i] = (int)g[i].size();
        if (degree[i] == 1 && ptr == -1)
            ptr = i;
    }
    vector<int> result;
    int leaf = ptr;
    for (int iter = 0; iter < n - 2; ++iter)
    {
        int next = parent[leaf];
        result.push_back(next);
        --degree[next];
        if (degree[next] == 1 && next < ptr)
            leaf = next;
        else
        {
            ++ptr;
            while (ptr < n && degree[ptr] != 1)
                ++ptr;
            leaf = ptr;
        }
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