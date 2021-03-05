#include <bits/stdc++.h>
using namespace std;
int main()
{
    iostream::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("BAI4.INP", "r", stdin);
    freopen("BAI4.OUT", "w", stdout);
    int n;
    cin >> n;
    vector<int> f(n + 2);
    f[1] = 1;
    f[2] = 2;
    f[3] = 4;
    for (int i = 4; i <= n; i++)
        f[i] = f[i - 1] % 1000000 + f[i - 2] % 1000000 + f[i - 3] % 1000000;
    cout << f[n] % 1000000;
}