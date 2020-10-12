#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
typedef pair<int, int> pii;

ifstream fi("slide.inp");
ofstream fo("slide.out");

int main()
{
    int n, m, p;
    fi >> n;
    vector<int> h(n);
    vector<pii> b(n);
    for (auto &i : h)
        fi >> i;
    p = 0;
    b[0] = {0, 1};
    for (int i = 1; i < n; i++)
    {
        if (h[i] == h[p])
        {
            ++b[p].ss;
        }
        else
        {
            h[++p] = h[i];
            b[p] = {i, 1};
        }
        m = p;
    }
    int k, w = n + 1;
    for (int i = 1; i < m; ++i)
    {
        if (h[i - 1] < h[i] && h[i] > h[i + 1] && w > b[i].ss)
        {
            w = b[i].ss;
            k = b[i].ff;
        }
    }
    if (w == n + 1)
        fo << "0";
    else
    {
        fo << k << " " << k + w + 1;
    }
}