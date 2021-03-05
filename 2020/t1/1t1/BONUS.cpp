#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("BONUS.inp", "r", stdin);
    freopen("BONUS.out", "w", stdout);
    int n;
    cin >> n;
    int a[100000];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int m;
    cin >> m;
    int b[100000];
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i];
    }
    int k;
    cin >> k;
    int u[100000], v[100000];
    for (int i = 1; i <= k; i++)
    {
        cin >> u[i] >> v[i];
    }

    int tong = 0;
    sort(b + 1, b + m + 1, greater<int>());
    if (m < n)
    {
        for (int i = m; i > 0; i--)
        {
            tong = tong + b[i];
        }
    }
    else
    {
        for (int i = n; i > 0; i--)
        {
            tong = tong + b[i];
        }
    }
    cout << tong;
}