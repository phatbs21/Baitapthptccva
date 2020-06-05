#include <bits/stdc++.h>
using namespace std;
#define ll long long int
const ll maxn = 200000;
ll s[20][170][1500];
ll a[20];
ll check(ll n)
{
    int c = 0, x = 0, y = 0;
    long long tong = 0, test = n;
    while (test > 0)
    {
        c++;
        a[c] = test % 10;
        test /= 10;
    }
    for (int i = c; i >= 1; i--)
    {
        for (int j = 0; j <= a[i] - 1; j++)
            if ((x + j <= 162) && (y + j * j <= 1458))
                tong += s[i - 1][x + j][y + j * j];
        x += a[i];
        y += a[i] * a[i];
    }
    tong += s[0][x][y];
    return tong;
}
int main()
{
    //freopen("SBT.INP", "r", stdin);
    //freopen("SBT.OUT", "w", stdout);
    for (int i = 1; i <= 162; i++)
    {
        for (int j = 1; j <= 1452; j++)
            if (__gcd(i, j) == 1)
                s[0][i][j] = 1;
    }
    for (int k = 1; k <= 18; k++)
        for (int i = 0; i <= 162; i++)
            for (int j = 0; j <= 1458; j++)
                for (int t = 0; t <= 9; t++)
                    if ((i + t <= 162) && (j + t * t <= 1458))
                        s[k][i][j] += s[k - 1][i + t][j + t * t];
    ll n, m;
    cin >> n >> m;
    if (n > m)
        cout << 0 << endl;
    else
        cout << check(m) - check(n - 1) << endl;
}