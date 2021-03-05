#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    string s1, s2;
    cin >> s1;
    cin >> s2;
    n = s1.length();
    m = s2.length();
    int f[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        f[i][0] = 0;
    }
    for (int j = 0; j <= m; j++)
    {
        f[0][j] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                f[i][j] = f[i - 1][j - 1] + 1;
            }
            else
            {
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
            }
        }
    }
    string xau;
    while (n > 0 && m > 0)
    {
        if (s1[n - 1] == s2[m - 1])
        {
            xau = char(s1[n - 1]) + xau;
            n--;
            m--;
        }
        else
        {
            if (f[n - 1][m] == f[n][m])
            {
                n--;
            }
            else
            {
                m--;
            }
        }
    }
    cout << xau+"  ";
}