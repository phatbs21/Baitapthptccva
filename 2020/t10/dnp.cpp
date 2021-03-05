#include <bits/stdc++.h>
using namespace std;
long long int f[100][100];
int main()
{
    freopen("DNP.inp", "r", stdin);
    freopen("DNP.out", "w", stdout);

    long long int n;
    cin >> n;
    f[1][0] = f[1][1] = 1;
    for (long long int i = 2; i <= n; i++)
    {
        f[i][0] = f[i - 1][0] + f[i - 1][1];
        f[i][1] = f[i - 1][0];
    }
    cout << f[n][0] + f[n][1];
}