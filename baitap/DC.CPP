#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxx = 1e9 + 7;
ll n, m, P, B, T;
struct Pot
{
    int luu;
    long long gia;
};
Pot nha[23];
bool cmp(Pot a, Pot b)
{
    return a.gia < b.gia;
}
int bus[10001];
ll chat(ll x)
{
    ll l = 1, r = P, mid;
    while (l != mid && r != mid)
    {
        mid = (l + r) / 2;
        if (bus[mid] <= x)
            l = mid;
        else
            r = mid;
    }
    ll kq = maxx;
    for (int i = l; i <= r; i++)
        kq = min(kq, abs(bus[i] - x));
    return kq;
}
ll cost(ll x, ll y)
{
    int xx = chat(x), yy = chat(y);
    ll tmp = (xx + yy) * T + B;
    return min(tmp, abs(x - y) * T);
}
void result()
{
    ll res = cost(1, nha[1].gia);
    for (int i = 2; i <= m; i++)
        res += cost(nha[i - 1].gia, nha[i].gia);
    res += cost(nha[m].gia, n);
    cout << res << endl;
}
int main()
{
    freopen("DC.INP", "r", stdin);
    freopen("DC.OUT", "w", stdout);
    cin >> n >> m >> P >> T >> B;
    for (int i = 1; i <= m; i++)
    {
        cin >> nha[i].gia;
        nha[i].luu = i;
    }
    sort(nha + 1, nha + 1 + m, cmp);
    bus[1] = 1;
    for (int i = 2; i <= P + 1; i++)
        cin >> bus[i];
    bus[P + 2] = n;
    P += 2;
    result();
    return 0;
}
