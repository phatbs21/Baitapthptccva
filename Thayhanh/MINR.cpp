#include <bits/stdc++.h>
using namespace std;
struct segmentTree
{
    vector<int> tree, a;
    int n;
    segmentTree()
    {
        n = 0;
    }
    segmentTree(int _n)
    {
        n = _n;
        tree.assign(n * 4 + 7, 0);
        a.resize(n + 1);
    }
    void build(int i, int l, int r)
    {
        if (l == r)
        {
            tree[i] = a[l];
            return;
        }
        int m = (l + r) / 2;
        build(i * 2, l, m);
        build(i * 2 + 1, m + 1, r);
        tree[i] = min(tree[2 * i], tree[2 * i + 1]);
    }

    int getMin(int i, int l, int r, int u, int v)
    {
        if (v < l || r < u)
        {
            return INT_MAX;
        }
        if (l >= u && r <= v)
        {
            return tree[i];
        }
        int m = (l + r) / 2;
        return min(getMin(2 * i, l, m, u, v), getMin(2 * i + 1, m + 1, r, u, v));
    }
    int getMin(int l, int r)
    {
        return getMin(1, 1, n, l, r);
    }
};
int main()
{
    int n, m;
    cin >> n >> m;
    segmentTree tree(n);
    for (int i = 1; i <= n; i++)
        cin >> tree.a[i];
    tree.build(1, 1, n);
    while (m--)
    {
        int w2, q1;
        ///cout << w2 << q1;
        cin >> w2 >> q1;
        cout << tree.getMin(w2, q1) << "\n";
    }
}