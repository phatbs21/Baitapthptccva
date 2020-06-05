#include <bits/stdc++.h>
using namespace std;
bool prime(int num)
{
    bool kq = true;
    for (int i = 2; i <= num / 2; i++)
    {
        if (num % i == 0)
        {
            kq = false;
            break;
        }
    }
    return kq;
}
int main()
{
    freopen("ROBOT2.inp", "r", stdin);
    int m, n;
    cin >> m >> n;
    int a[101][101], d[101][101];
    int c[101][101], b[101][101];
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (prime(abs(a[i][j]) - a[i + 1][j]) || (prime(abs(a[i][j] - a[i][j + 1]))))
            {
                b[i][j] = 1;
            }
            else
            {
                b[i][j] = 0;
            }
        }
    }
    for (int i = m; i >= 1; i--)
    {
        for (int j = n; j >= 1; j--)
        {
            if (prime(abs(a[i][j]) - a[i - 1][j]) || (prime(abs(a[i][j] - a[i][j - 1]))))
            {
                c[i][j] = 1;
            }
            else
            {
                c[i][j] = 0;
            }
        }
    }

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; i++)
        {
            d[i][j] = b[i][j] & c[i][j];
        }
    }
    for (int i)
}
