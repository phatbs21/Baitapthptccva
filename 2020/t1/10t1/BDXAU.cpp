#include <bits/stdc++.h>

using namespace std;
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Og")
#pragma GCC push_options
#pragma GCC pop_options
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("BDXAU.INP", "r", stdin);
    freopen("BDXAU.OUT","w",stdout);
    string x, y;
    getline(cin, x);
    getline(cin, y);
    int f[101][101];
    int i, j, m, n;
    x = " " + x;
    y = " " + y;
    n = x.length();
    m = y.length();
    f[0][0] = 0;
    for (i = 1; i <= n; i++)
    {
        f[i][0] = i;
    }
    for (j = 1; i <= m; j++)
    {
        f[0][j] = j;
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            if (x[i] == y[j])
            {
                f[i][j] = f[i - 1][j - 1];
            }
            else
            {
                f[i][j] = min((f[i - 1][j - 1]), min((f[i][j - 1]), (f[i - 1][j]))) + 1;
            }
        }
    }
    cout << f[n][m] << endl;
    i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (x[i] == y[j])
        {
            i--;
            j--;
        }
        else
        {
            if (f[i][j] == f[i - 1][j - 1] + 1)
            {
                cout << "R " << i << " " << y[j] << endl;
                i--;
                j--;
            }
            else
            {
                if (f[i][j] == f[i][j - 1] + 1)
                {
                    cout << "I " << i << " " << y[j] << endl;
                    j--;
                }
                else
                {
                    cout << "D " << i << endl;
                    i--;
                }
            }
        }
    }
    while (j > 0)
    {
        cout << "I " << 1 << y[j] << endl;
        j--;
    }
    while (i > 0)
    {
        cout << "D " << 1 << endl;
        i--;
    }
    return 0;
}
