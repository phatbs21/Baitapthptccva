#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x, y, z;
    cin >> n >> x >> y >> z;
    int a[n + 1], b[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
    }
    int f[100][100];
    int p = 0, q = 0;
    for (int i = 1; i <= n; i++)
    {
        p += a[i];
        q += b[i];
    }
    int A[p + 1], B[q + 1];
    int dem = 0,dem2=0,j=1;

    for (int i = 1; i <= n; i++)
    {
        dem++;
        while (j<=a[i])
        {
            A[j]=dem;
            j++;
        }
    }
    for (int i = 1; i <= q; i++)
    {
        for (int j = 1; j <= p; j++)
        {
            f[i][j] = min(y + f[i - 1][j], min(f[i][j - 1] + x, f[i - 1][j - 1] + z * abs(a[i] - b[j])));
        }
    }
    cout << f[n][n];
}