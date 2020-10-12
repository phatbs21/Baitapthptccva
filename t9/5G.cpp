#include <bits/stdc++.h>
#define NAME "5G."
#define ff first
#define ss second
using namespace std;
ifstream fi(NAME "inp");
ofstream fo(NAME "out");
typedef pair<int, int> pii;
int main()
{
    int n, a, b;
    fi >> n;
    vector<pii> seg(2 * n);
    for (int i = 0; i < n; ++i)
    {
        fi >> a >> b;
        seg[2 * i] = {a, 0};
        seg[2 * i + 1] = {b, 1};
    }
    sort(seg.begin(), seg.end());
    int p = 0, k = 0;
    a = seg[0].ff;
    b = a;
    for (int i = 0; i < n; ++i)
    {
        if (seg[i].ss == 0)
        {
            if (p == 0)
                a = seg[i].ff;
            ++p;
            continue;
        }
        if (seg[i].ff > b)
            b = seg[i].ff;
        --p;
        if (p == 0)
        {
            if (k > 0 && seg[k - 1].ss + 1 == a)
                seg[k - 1].ss = b;
            else
                seg[k++] = {a, b};
        }
    }
    seg.resize(k);
    fo << k << '\n';
    for (auto e : seg)
        fo << e.ff << ' ' << e.ss << '\n';
}
