#include <bits/stdc++.h>
using namespace std;
long long int n, a[100009], f[1000009], tg = 0;
int main()
{
    freopen("toys.inp", "r", stdin);
    freopen("toys.out", "w", stdout);
    cin >> n;
    for (long long int i = 1; i <= n; ++i)
        cin >> a[i];
    memset(f, 0, sizeof(f));
    f[n] = a[n];
    f[n - 1] = a[n - 1] + a[n];
    f[n - 2] = f[n - 1] + a[n - 2];
    for (long long int i = n - 3; i >= 1; i--)
    {
        tg = 0;
        for (long long int x = 0; x < 3; x++)
        {
            tg += a[i + x];
            f[i] = max(f[i], tg + f[i + 2 * x + 2]);
        }
    }
    cout << f[1];
    return 0;
}
