#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("caitui.inp", "r", stdin);
    long long int n, w;
    cin >> n >> w;
    long long int m[n + 10], v[n + 10];

    long long int tong = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> m[i] >> v[i];
        tong += v[i];
    }
    long long int f[tong + 10];
    for (int i = 1; i <= tong; i++)
    {
        f[i] = 1000000000;
    }
    f[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int t = tong; t >= v[i]; t--)
        {
            f[t] = min(m[i] + f[t - v[i]], f[t]);
        }
    }
    for (int t = tong; t >= v[1]; t--)
    {
        if (f[t] <= w)
        {
            cout << t;
            return 0;
        }
    }
}