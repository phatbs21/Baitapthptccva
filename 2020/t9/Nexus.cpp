#include <bits/stdc++.h>
using namespace std;
#define NAME "Nexus"
typedef tuple<int, int, int> tii;

ifstream fi(NAME ".inp");
ofstream fo(NAME ".out");
int main()
{
    int n, tp, imxa, mxa, k;
    fi >> n;
    vector<int> a(n), rounds(n, 0);
    for (int i = 0; i < n; i++)
    {
        fi >> tp;
        a[i] = tp;
        if (mxa < tp)
            mxa = tp, imxa = i;
    }
    rotate(a.begin(), a.begin() + imxa, a.end());
    a.push_back(mxa);
    vector<tii> st(n + 1);
    st[0] = make_tuple(0, 0, 0);
    st[1] = make_tuple(mxa, imxa, 0);
    tp = 1;
    k = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[i - 1] && a[i] < a[i + 1])
            k = 0;
        st[++tp] = make_tuple(a[i], i, 0);
        while (get<0>(st[tp - 1]) > get<0>(st[tp]) && a[i + 1] > get<0>(st[tp]) && !(i == n - 1 && tp == 2))
        {
            rounds[(get<1>(st[tp]) + imxa) % n] = ++k;
            --tp;
            get<2>(st[tp]) = k;
        }
    }
    for (int i : rounds)
        fo << i << " ";
}