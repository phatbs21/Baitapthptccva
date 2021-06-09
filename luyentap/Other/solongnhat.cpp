//https://lqdoj.edu.vn/problem/dplcs2
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string x = "60005", y = "90204";

    //cin >> x;
    //cin.ignore();
    //cin >> y;
    int n = x.length();
    int m = y.length();
    int f[101][101];
    memset(f, 0, sizeof(f));
    string kq;
    while (y[0] == '0')
    {
        m--;
        y.erase(0, 0 + 1);
    }
    while (x[0] == '0')
    {
        n--;
        x.erase(0, 0 + 1);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (x[i] == y[j])
                f[i][j] = f[i - 1][j - 1] + 1;
            else
                f[i][j] = max(f[i - 1][j], f[i][j - 1]);
        }
    }
    cout << f[n - 1][m - 1];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << f[i][j] << " ";
        cout << endl;
    }
    
    while (n > 0 && m > 0)
    {
        if (x[n] == y[m])
        {
            kq = x[n] + kq;
            n--, m--;
        }
        else
        {
            if (f[n - 1][m] == f[n][m - 1])
                if (x[n] >= y[n])
                    f[n - 1][m]--;
                else
                    f[n][m - 1]--;
            if (f[n][m] == f[n - 1][m])
            {
                n--;
            }
            else
                m--;
        }
    }
    cout << kq;
    
}