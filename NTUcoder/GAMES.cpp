#include <bits/stdc++.h>
using namespace std;

struct SegmentTree
{
    const long long int MOD = 998244353;
    vector<long long int> tree, lazy, a;
    long long int n;

    SegmentTree()
    {
        n = 0;
    }

    SegmentTree(long long int _n)
    {
        n = _n;
        a.resize(n + 1);
        tree.assign(4 * n + 7, 0);
        lazy.assign(4 * n + 7, 0);
    }

    void build(long long int i, long long int l, long long int r)
    {

        if (l == r)
        {
            tree[i] = a[l];
            return;
        }
        long long int m = (l + r) / 2;
        build(2 * i, l, m);
        build(2 * i + 1, m + 1, r);
        tree[i] = max(tree[i * 2], tree[2 * i + 1]);
    }
    void pushDown(long long int i, long long int l, long long int r)
    {
        if (lazy[i] == 0)
            return;
        lazy[i * 2] = lazy[i];
        lazy[i * 2 + 1] = lazy[i];
        tree[i * 2] = lazy[i];
        tree[i * 2 + 1] = lazy[i];
        lazy[i] = 0;
    }

    void update(long long int i, long long int l, long long int r, long long int u, long long int v, long long int c)
    {
        if (l > v || r < u)
            return;
        if (u <= l && r <= v)
        {
            tree[i] = c;
            lazy[i] = c;
            return;
        }
        pushDown(i, l, r);
        long long int m = (l + r) / 2;
        update(2 * i, l, m, u, v, c);
        update(2 * i + 1, m + 1, r, u, v, c);
        tree[i] = max(tree[2 * i], tree[2 * i + 1]);
    }

    long long int getMax(long long int i, long long int l, long long int r, long long int u, long long int v)
    {
        if (l > v || r < u)
        {
            return INT_MIN;
        }
        if (l >= u && r <= v)
            return tree[i];
        pushDown(i, l, r);
        long long int m = (l + r) / 2;
        long long int x = getMax(2 * i, l, m, u, v);
        long long int y = getMax(2 * i + 1, m + 1, r, u, v);
        return max(x, y);
    }

    void update(long long int l, long long int r, long long int c)
    {
        update(1, 1, n, l, r, c);
    }
    long long int getMax(int u, int v)
    {
        return getMax(1, 1, n, u, v);
    }
};
int main()
{
    long long int n, m;
    cin >> n >> m;
    SegmentTree tree(n);
    for (long long int i = 1; i <= n; i++)
        cin >> tree.a[i];
    tree.build(1, 1, n);
    for (long long int t = 1; t <= m; t++)
    {
        long long int x, y;
        cin >> x >> y;
        long long int temp = tree.getMax(x, x + y - 1) + 1;
        cout << temp << "\n";
        tree.update(x, x + y - 1, temp);
    }
}
