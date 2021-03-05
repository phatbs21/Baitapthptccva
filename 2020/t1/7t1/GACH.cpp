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
    freopen("GACH.INP", "r", stdin);
    freopen("GACH.OUT", "w", stdout);
    long long int n;
    cin >> n;
    long long int a[n + 1];
    for (long long int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    if (a[n]==0)
    {
        cout<<1;
        return 0;
    }
    long long int f[n+10];
    f[1]=1;
    f[2]=2;
    for (long long int i=3;i<=n;i++)
    {
        f[i]=min(f[i-1],a[i])+1;
    }
    long long int max = f[1];
    for (long long int i = 2; i <= n; i++)
        if (max < f[i])
            max = f[i];
    cout << max;
}