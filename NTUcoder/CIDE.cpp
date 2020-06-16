#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m, n, d = 1, a[101];
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    int k = n;
    while (d < m && k > 0)
    {
        d += a[k] - 1;
        k--;
    }
    if (d < m)
        cout << -1;
    else
        cout << n - k;
    return 0;
}
