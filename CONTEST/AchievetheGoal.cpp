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
    int n;
    cin >> n;
    int k;
    cin >> k;
    int m;
    cin >> m;
    int a[n];
    int tong = 0;
    for (int i = 1; i < n; i++)
    {
        cin >> a[i];
        tong += a[i];
    }
    for (int i = 0; i <= k; i++)
    {
        tong = tong + i;
        if ((tong / n) >= m)
        {
            cout << i;
            return 0;
        }
        else
        {
            tong = tong - i;
        }
    }
    cout << -1;
    return 0;
}