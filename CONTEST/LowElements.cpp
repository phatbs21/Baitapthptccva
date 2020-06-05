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
    long long int n;
    cin >> n;
    long long int a[n + 1];
    bool d[n + 1];
    for (long long int i = 1; i <= n; i++)
    {
        cin >> a[i];
        d[i] = true;
    }
    long long int i = 1;
    long long int dem = n;
    long long int z = 1;
    while (n > i)
    {
        if (a[i] <= a[i + z] && d[i] != false && i+z <= n)
        {
            dem--;
            d[i + z] = false;
            z++;
            continue;
        }
        i++;
        z = 1;
    }
    cout << dem;
}