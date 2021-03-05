#include <bits/stdc++.h>
using namespace std;
struct segMentTree
{
    int n;
    vector<int> tree, a;
    segMentTree()
    {
        n = 0;
    }
    segMentTree(int _n)
    {
        n = _n;
        a.resize(n + 1);
        tree.assign(4 * n + 4, 0);
    }
    void build(int i, int l, int r, int u, int v)
    {
        if (l > v || r < u)
            return;
        if (l >= u && r <= v)
        {
            tree[i] = a[l];
            return;
        }
        int m = (l + r) >> 1;
        build(2 * i, l, m, u, v);
        build(2 * i + 1, m + 1, r, u, v);
        tree[i] = max(tree[2 * i], tree[i * 2 + 1]);
    }
    void update(int i, int l, int r, int u, int v, int c)
    {
        if (l > r || r < u)
            return;
        if (l >= u && r <= v)
        {
            tree[i] = c;
        }
        int m = (l + r) >> 1;
        update(2 * i, l, m, u, v, c);
        update(2 * i + 1, m + 1, r, u, v, c);
    }
    
};

int main()
{
    int n, k;
    cin >> n >> k;
}