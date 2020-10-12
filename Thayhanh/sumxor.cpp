#include <bits/stdc++.h>

using namespace std;
#define NAME "sumxor"
#define tocdo cout << "Time " << clock() / (double)1000 << " sec"
ifstream fi(NAME ".inp");
ofstream fo(NAME ".out");
//lower_blound : tim so lon  hon hoac bang a[i] trong day nay

const int N = 1e6 + 10;

struct node
{
    int l, r, id;
    friend bool operator<(const node &a, const node &b)
    {
        return a.l == b.l ? a.r < b.r : a.l < b.l;
    }
} q[N];

int a[N], c[N], nxt[N];
int n, m;
int ans[N], s[N];
int l;
unordered_map<int, int> mp;

void update(int x, int val)
{
    for (; x <= n; x += x & -x)
        c[x] ^= val;
}

int query(int x)
{
    int ret = 0;
    for (; x; x -= x & -x)
        ret ^= c[x];
    return ret;
}

void undo(int x)
{
    update(x, a[x]);
    if (nxt[x])
        update(nxt[x], a[nxt[x]]);
}

int main()
{
    freopen("sumxor.inp", "r", stdin);
    freopen("sumxor.out", "w", stdout);
    int test;
    cin >> test;
    mp.clear();
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] ^ a[i];
    for (int i = 1; i <= n; i++)
    {
        if (mp.count(a[i]))
            continue;
        else
        {
            mp[a[i]] = 1;
            update(i, a[i]);
        }
    }
    mp.clear();
    for (int i = n; i >= 1; i--)
    {
        nxt[i] = (mp.count(a[i])) ? mp[a[i]] : 0;
        mp[a[i]] = i;
    }
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }
    sort(q + 1, q + m + 1);
    l = 1;
    for (int i = 1; i <= m; i++)
    {
        while (l < q[i].l)
        {
            undo(l);
            ++l;
        }
        ans[q[i].id] = query(q[i].r) ^ s[q[i].r] ^ s[q[i].l - 1];
    }

    for (int i = 1; i <= m; i++)
        cout << ans[i] << " ";
    return 0;
}
