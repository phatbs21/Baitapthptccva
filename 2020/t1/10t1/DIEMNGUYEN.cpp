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
    freopen("DIEMNGUYEN.INP", "r", stdin);
    freopen("DIEMNGUYEN.OUT", "w", stdout);
    long int n;
    cin >> n;
    long int x[n + 1], y[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> x[i] >> y[i];
    }
    long int tongx = 0, tongy = 0;
    int tong = 0;
    for (int i = 1; i < n; i++)
    {
        tongx = abs(x[i] - x[i + 1]);
        tongy = abs(y[i] - y[i + 1]);
        tong += __gcd(tongx, tongy);
        //cout << tongx << " " << tongy << endl;
    }
    tongx = abs(x[n] - x[1]);
    tongy = abs(y[n] - y[1]);
    tong+=__gcd(tongx, tongy);
    cout << tong;
}