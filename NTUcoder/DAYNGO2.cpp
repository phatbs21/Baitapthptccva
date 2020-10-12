#include <bits/stdc++.h>
using namespace std;
struct segMentTree
{
    vector<int> tree, a;
    int n;
    segMentTree()
    {
        n = 0;
    }
    segMentTree(int _n)
    {
        n = _n;
        tree.assign(4 * n + 7, 0);
        a.assign(n + 1, 0);
    }
    void build(int i, int l, int r)
    {
        if (r == l)
        {
            tree[i] = a[l];
            return;
        }
        int m = (l + r) / 2;
        build(2 * i, l, m);
        build(2 * i + 1, m + 1, r);
        tree[i] = min(tree[2 * i], tree[2 * i + 1]);
    }
    int get(int i, int l, int r, int u, int v)
    {
        if (r < u || l > v)
        {
            return 1e7;
        }
        if (l >= u && r <= v)
        {
            return tree[i];
        }
        int mid = (l + r) / 2;
        return min(get(2 * i, l, mid, u, v), get(2 * i + 1, mid + 1, r, u, v));
    }
    int get(int l, int r)
    {
        return get(1, 1, n, l, r);
    }
};
int main()
{
    int n, m;
    cin >> n >> m;
    string s, s1;
    cin >> s1;
    s = ' ' + s1;
    segMentTree tree(n);
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == '(')
        {
            tree.a[i] = tree.a[i - 1] + 1;
        }
        else
            tree.a[i] = tree.a[i - 1] - 1;
    }
    tree.build(1, 1, n);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        if (tree.get(x, y) == tree.a[x - 1] && tree.a[x - 1] == tree.a[y])
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }
}