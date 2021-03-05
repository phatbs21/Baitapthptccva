#include <bits/stdc++.h>
using namespace std;

int main()
{
    int u, n;
    queue<int> q;
    freopen("DFS.inp", "r", stdin);
    cin >> n;
    int a[n + 1][n + 1];
    bool d[n+1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
        d[i] = false;
    q.push(4);
    d[4] = true;
    while (!q.empty())
    {
        u = q.front();
        cout << "Xet dinh " << u << endl;
        q.pop();
        for (int v = 1; v <= n; v++)
        {
            if (a[u][v] > 0 && d[v] == false)
            {
                q.push(v);
                d[v] = true;
            }
        }
    }
}
