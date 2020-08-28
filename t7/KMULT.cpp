#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int f[100][100], u;
    f[1][(a[1] % k + k) % k] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < k; ++j)
        {

            u = ((j + a[i + 1] % k) % k + k) % k;
            f[i + 1][u] = 1;
            u = ((j - a[i + 1] % k) % k + k) % k;
            f[i + 1][u] = 1;
        }
    }
    int j = 0;
    int dau[1000];
    if (f[n][0]==0)
    {
        cout<<0;
        return 0;
    }
    else cout<<1;
    for (int i = n; i > 1; --i)
    {
        u = ((j - a[i] % k) % k + k) % k;
        if (f[i - 1][u])
        {
            dau[i] = 1;
            j = u;
        }
        else
        {
            dau[i]=-1;
            j=((f[i][j]+a[i]%k)%k+k)%k;
        }
        cout<<dau[i];
    }
    for (int i=)
}