#include <bits/stdc++.h>
using namespace std;

const int oo = 1000111000;
int a[1000][1000];
int n, m;

void minimize(int &a, int b)
{
    if (a > b)
        a = b;
}

int main()
{
    int z;
    cin >> n >> m >> z;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] = oo;
    for (int i = 1; i <= n; i++)
        a[i][i] = 0;

    for (int i = 1; i <= m; i++)
    {
        int p, q, w;
        cin >> p >> q >> w;
        a[p][q] = a[q][p] = w;
    }

    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                minimize(a[i][j], a[i][k] + a[k][j]);
    for (int i = 1; i <= z; i++)
    {
        int x, y;
        cin >> x >> y;
        cout << a[x][y] << "\n";
        
    }
}
