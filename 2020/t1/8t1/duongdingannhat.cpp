#include <bits/stdc++.h>
using namespace std;
int s, t, T[1000];
void viet()
{
    int p[1000], z = 1;
    int i = t;
    while (i != s)
    {
        p[z] = i;
        z++;
        i = T[i];
    }
    p[z] = s;
    for (i = z; i >= 1; i--)
        cout << p[i] << " ";
    cout << endl;
}
int main()
{
    int u, n;
    queue<int> q;
    freopen("duongdi.inp", "r", stdin);
    cin >> n >> s >> t;
    int a[n + 1][n + 1];
    bool d[n + 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
        d[i] = false;
    q.push(s);
    d[s] = true;
    while (!q.empty())
    {
        u = q.front();
        q.pop();
        for (int v = 1; v <= n; v++)
        {
            if (a[u][v] > 0 && d[v] == false)
            {
                q.push(v);
                d[v] = true;
                T[v] = u;
                if (v == t)
                {
                    viet();
                    return 0;
                }
            }
        }
    }
}
