#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Og")
#pragma GCC push_options
#pragma GCC pop_options

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("daycon.inp", "r", stdin);
    freopen("daycon.out", "w", stdout);
    long long int n;
    cin >> n;
    long long int a[n + 10];
    long long int f[n+10];
    f[0]=0;
    f[n] = 0;
    for (long long int i = 1; i <= n; i++)
    {
        cin >> a[i];
        //f[n] += a[i];
    }
    f[n] = a[n];
    for (long long int i = n-1; i > 0; i--)
    {
        f[i] = max(a[i], a[i] + f[i + 1]);
    }
    long long int max = f[1];
    for (long long int i = 2; i <= n; i++)
        if (max < f[i])
            max = f[i];
    cout << max;
}