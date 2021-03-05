#include <bits/stdc++.h>
using namespace std;
#define NAME "Transport"
ifstream fi(NAME ".inp");
ofstream fo(NAME ".out");
int n, h, fm = 1;
int64_t ans = 0;

int main()
{
    fi >> n >> h;
    vector<int> r(n), f(n);
    for (int i = 0; i < n; ++i)
        fi >> r[i] >> f[i];
    for (int i = 0; i < n; ++i)
        fm = max(fm, min(f[i], max(1, r[i] - h + 1)));
    for (int i = 0; i < n; ++i)
        if (f[i] > fm)
            ans += (int64_t)(f[i] - fm);
    fo << ans;
    cout << "Time " << clock() / (double)1000 << " sec";
}