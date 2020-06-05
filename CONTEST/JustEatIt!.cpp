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
    long long int t;
    cin >> t;
    for (long long int q = 1; q <= t; q++)
    {
        long long int n;
        cin >> n;
        long long int a[n + 1];
        long long int tong = 0;
        bool w = false;
        for (long long int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for (long long int i = 1; i <= n; i++)
        {
            tong = tong + a[i];
            if (tong <= 0)
            {
                cout << "NO" << endl;
                w = true;
                break;
            }
        }
        tong = 0;
        if (w == true)
            continue;
        for (long long int i = n; i >= 1; i--)
        {
            tong = tong + a[i];
            if (tong <= 0)
            {
                cout << "NO" << endl;
                w = true;
                break;
            }
        }
        if (w == true)
            continue;
        cout << "YES" << endl;
        continue;
    }
}