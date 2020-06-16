#include <bits/stdc++.h>
using namespace std;
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, k;
    long a[300000], t = 0;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            a[t] = i * j;
            t++;
        }
    sort(a, a + t);
    cout << a[k - 1];
}
