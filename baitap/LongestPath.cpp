#include <bits/stdc++.h>
using namespace std;
int f[1000];

void DFS(int u)
{
    if (f[u] > 0)
    {
        return;
    }
    int kq = 0;
    for (int v = 1; v <= u; v++)
    {
        DFS(v);
        kq = max(kq, f[v]);
        f[u] = kq;
    }
}
int main()
{
    struct LongestPath
    {
        int a, b;
    };

    int n, m;
    cin >> n >> m;
    LongestPath a[m + 1];
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i].a >> a[i].b;
    }
    memset(f, -1, sizeof(f));
    for (int u = 1; u <= n; u++)
    {
        DFS(u);
    }
}