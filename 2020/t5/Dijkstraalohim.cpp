#include <iostream>

int main()
{
    int dem = 0;
    int n;
    std::cin >> n;
    int s, t;
    std::cin >> s >> t;
    int chuaxet[n+1];
    int a[n+1][n+1];
    int d[n+1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            std::cin >> a[i][j];
            if (a[i][j] == -1)
                a[i][j] = 100000;
        }
    }
    int ttt, u;
    for (int v = 1; v <= n; v++)
    {
        d[v] = a[s][v];
        chuaxet[v] = 0;
    }
    d[s] = 0;
    chuaxet[s] = 1;
    while (!chuaxet[t])
    {
        ttt = 100000;
        dem++;
        for (int v = 1; v <= n; v++)
        {
            if ((!chuaxet[v]) && (ttt > d[v]))
            {
                u = v;
                ttt = d[v];
            }
        }
        chuaxet[u] = 1;
        if (!chuaxet[t])
        {
            for (int v = 1; v <= n; v++)
            {
                if ((!chuaxet[v]) && (d[u] + a[u][v] < d[v]))
                {
                    d[v] = d[u] + a[u][v];
                }
            }
        }
        if (dem > 101)
        {
            std::cout << -1;
            return 0;
        }
    }
    std::cout << d[t];
}