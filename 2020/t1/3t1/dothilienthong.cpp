#include <bits/stdc++.h>
using namespace std;
// Remove GCC optimizer for codechef

int main()
{
    freopen("test.inp", "r", stdin);
    int n;
    cin >> n;
    int a[n + 10][n + 10];
    bool p[n + 10];
    for (int i = 1; i <= n; i++)
    {
        p[i] = false;
        for (int j = 1; j <= n; j++)
            cin >> a[i][j];
    }
    int c = 1, d = 1;
    int q[n + 10];
    q[1] = 1;
    p[1] = true;
    int u;
    while (d <= c)
    {
        u = q[d];
        for (int v = 1; v <= n; v++)
        {
            if (a[u][v] > 0 && p[v] == false)
            {
                c++;
                q[c]=v;
                p[v] = true;
            }
        }
        d++;
    }
 
    if (c == n)
    {
        cout << "do thi lien thong";
    }
    else
    {
        cout << "do thi khong lien thong";
    }
}