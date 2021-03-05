#include <bits/stdc++.h>
using namespace std;
int a[100001][4];
int f[100001][4];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i][1] >> a[i][2] >> a[i][3];

    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 3; j++)
        {
            for (int k = 1; k <= 3; k++)
            {
                if (j != k)
                    f[i][j] = max(f[i][j], a[i][j] + f[i - 1][k]);
            }
        }
    }
    int res = 0;
    for (int i = 1; i <= 3; i++)
    {
        res = max(res, f[n][i]);
    }
    cout << res;
}