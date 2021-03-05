#include <bits/stdc++.h>
using namespace std;
int n, x[1000], a[100][100];
bool d[1000];
int dfs(int u, int k)
{
    d[u] = true;
    x[k] = u;
    for (int v = 1; v <= n; v++)
    {
        if (a[u][v] > 0 && u != v)
        {
            if (d[v] = false)
            {
                dfs(v, k + 1);
            }
            else if (x[k - 1] != v)
            {
                int t = k;
                while (x[t] != v && t > 1)
                {
                    cout << x[t];
                    t--;
                }
                cout << v;
            }
        }
    }
    return 0;
}
int main()
{
    memset(d, false, sizeof(d));
    //freopen("chutrinhdothi.inp", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    dfs(1, 1);
}