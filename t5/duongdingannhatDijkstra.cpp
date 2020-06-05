#include <bits/stdc++.h>
using namespace std;

#define TRUE 1
#define FALSE 0
int chuaxet[10000];
int a[1000][1000];
int d[1000];
int truoc[1000];
int main()
{
    int n;
    cin >> n;
    int s, t;
    cin >> s >> t;
    cout << "So dinh : " << n << endl;

    for (int i = 1; i <= n; i++)
    {

        for (int j = 1; j <= n; j++)
        {

            cin >> a[i][j];

            if (a[i][j] == 0)
                a[i][j] = 1e9;
        }
    }

    int ttt, u;
    for (int v = 1; v <= n; v++)
    {

        d[v] = a[s][v];

        truoc[v] = s;

        chuaxet[v] = FALSE;
    }
    truoc[s] = 0;

    d[s] = 0;

    truoc[s] = 0;

    chuaxet[s] = TRUE;

    while (!chuaxet[t])
    {
        ttt = 1e9;

        for (int v = 1; v <= n; v++) //tim dinh u ma d[u] nho nhat
        {
            if ((!chuaxet[v]) && (ttt > d[v]))
            {
                u = v;
                ttt = d[v];
            }
        }

        chuaxet[u] = TRUE; // co dinh dinh u

        if (!chuaxet[t])
        {
            for (int v = 1; v <= n; v++)
            {
                if ((!chuaxet[v]) && (d[u] + a[u][v] < d[v]))
                {
                    d[v] = d[u] + a[u][v];
                    truoc[v] = u;
                }
            }
        }
    }
    cout << "Duong di ngan nhat tu " << s << " den " << t << " la" << endl;

    cout << t << "<=";

    int i = truoc[t];

    while (i != s)
    {

        cout << i << "<=";

        i = truoc[i];
    }
    cout << s;
    cout << endl
         << "Do dai duong di la : " << d[t];
}