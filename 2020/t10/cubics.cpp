#include <bits/stdc++.h>
#define lli long long int

using namespace std;

int main()
{
    lli n, k, x, s = 0, m = -1, v;
    map<int, int> f;
    freopen("cubics.inp", "r", stdin);
    freopen("cubics.out", "w", stdout);
    cin >> n >> k;
    for (lli i = 1; i <= n; ++i)
    {
        cin >> x;
        x = x - k;
        s += x;
        if (f[s] == 0)
            f[s] = i;
        else
        {
            if (m < i - f[s])
            {
                m = i - f[s];
                v = i;
            }
        }
    }
    if (m >= 1)
        cout << m << " " << v - m + 1;
    else
        cout << 0;
}
