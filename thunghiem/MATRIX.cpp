#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("MATRIX.INP", "r", stdin);
    //freopen("MATRIX.OUT", "w", stdin);
    int m, n, *s;
    cin >> m;
    int dem1 = 0, dem2 = 0;
    int q[m][m];
    s = (int *)malloc(sizeof(int) * m * m);
    for (int i = n = 0; i < m * 2; i++)
        for (int j = (i < m) ? 0 : i - m + 1; j <= i && j < m; j++)
            s[(i & 1) ? j * (m - 1) + i : (i - j) * m + j] = n++;
    int z = 0;
    for (int i = 0; i < m * m; (++i % m) ? dem2++ : dem1++)
    {
        if (dem1 != z)
        {
            z = dem1;
            dem2++;
        }
        if (dem2 == m)
        {
            dem2 = 0;
        }
        q[dem1][dem2] = s[i] + 1;
    }
    delete (s);
    int k;
    cin >> k;
    string xau;
    cin >> xau;
    dem1 = 0;
    dem2 = 0;
    long long int tong = 0;
    for (int i = 0; i < k; i++)
    {
        tong += q[dem1][dem2];
        if (xau[i] == 'D')
        {
            dem1++;
        }
        else if (xau[i] == 'U')
        {
            dem1--;
        }
        else if (xau[i] == 'L')
        {
            dem2--;
        }
        if (xau[i] == 'R')
        {
            dem2++;
        }
    }
    tong += q[dem1][dem2];
    cout << tong;
    return 0;
}
