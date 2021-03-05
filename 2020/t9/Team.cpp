#include <bits/stdc++.h>
using namespace std;
#define NAME "Team"
#define tocdo cout << "Time " << clock() / (double)1000 << " sec"
ifstream fi(NAME ".inp");
ofstream fo(NAME ".out");
#define ff first
#define ss second
typedef pair<int64_t, int64_t> pll;
int64_t a, b, t, s = 0;
int n, ia;

int main()
{
    fi >> n;
    vector<pll> ba(n);
    vector<int64_t> f(n);
    for (int i = 0; i < n; i++)
    {
        fi >> a >> b;
        ba[i] = {b, a};
    }
    sort(ba.begin(), ba.end());
    a = 1e9 + 1;
    b = 0;
    for (int i = 0; i < n; i++)
    {
        if (ba[i].ss < a)
        {
            a = ba[i].ss;
            ia = i;
        }
    }
    for (int i = 0; i < n; i++)
    {
        t = ba[i].ff - ba[i].ss;
        if (b < t)
            b = t;
        if (i < ia)
        {
            f[i] = s + a;
            s += ba[i].ff;
            continue;
        }
        s += ba[i].ff;
        f[i] = s - b;
    }
    for (int i = 0; i < n; i++)
        fo << f[i] << "\n";
    tocdo;
}
