#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

struct SegmentTree
{
    vector<int> tree, lazy;
    int n;

    SegmentTree()
    {
        n = 0;
    }

    SegmentTree(int _n)
    {
        n = _n;
        tree.assign(4 * n + 7, 0);
        lazy.assign(4 * n + 7, 0);
    }

    // đẩy thông tin lazy update từ nút i quản lý đoạn (l, r) xuống hai nút con
    void pushDown(int i, int l, int r)
    {
        int m = (l + r) >> 1;
        tree[2 * i] = (tree[2 * i] + 1LL * lazy[i] * (m - l + 1)) % MOD;
        tree[2 * i + 1] = (tree[2 * i + 1] + 1LL * lazy[i] * (r - m)) % MOD;
        lazy[2 * i] = (lazy[2 * i] + lazy[i]) % MOD;
        lazy[2 * i + 1] = (lazy[2 * i + 1] + lazy[i]) % MOD;
    }

    // đang xét nút i quản lý đoạn (l, r), cần cập nhật tăng đoạn (u, v) thêm c
    void update(int i, int l, int r, int u, int v, int c)
    {
        // trường hợp hai đoạn (l, r) và (u, v) không giao nhau
        if (l > v || r < u || l > r || v < u)
            return;

        // trường hợp cả đoạn (l, r) nằm trong đoạn (u, v), nghĩa là cả đoạn cần tăng
        if (u <= l && r <= v)
        {
            tree[i] = (tree[i] + c) % MOD;
            lazy[i] = (lazy[i] + c) % MOD;
            return;
        }

        pushDown(i, l, r);
        int m = (l + r) >> 1;
        update(2 * i, l, m, u, v, c);
        update(2 * i + 1, m + 1, r, u, v, c);

        tree[i] = (tree[2 * i] + tree[2 * i + 1]) % MOD;
    }

    // đang xét nút i quản lý đoạn (l, r), cần tính tổng các số từ u đến v
    int getSum(int i, int l, int r, int u, int v)
    {
        // trường hợp hai đoạn (l, r) và (u, v) không giao nhau
        if (l > v || r < u || l > r || v < u)
            return 0;

        // trường hợp cả đoạn (l, r) nằm trong đoạn (u, v), nghĩa là cả đoạn cần tăng
        if (u <= l && r <= v)
            return tree[i];

        pushDown(i, l, r);
        int m = (l + r) >> 1;
        int L = getSum(2 * i, l, m, u, v);
        int R = getSum(2 * i + 1, m + 1, r, u, v);
        return (L + R) % MOD;
    }

    void update(int l, int r, int c)
    {
        update(1, 1, n, l, r, c);
    }

    int getSum(int l, int r)
    {
        return getSum(1, 1, n, l, r);
    }
};
int main()
{
    int n;
    cin >> n;
    SegmentTree itOne(n);     // cây segment tree itOne quản lý dãy độ dài n
    SegmentTree itTwo(n * 2); // cây segment tree itTwo quản lý dãy độ dài n * 2
    // tăng đoạn từ 1 đến 10 thêm 20 ở cây itOne
    itOne.update(1, 10, 20);
    // tính tổng đoạn từ 3 đến 5 ở cây itOne
    cout << itOne.getSum(3, 5) << endl;

    // tăng đoạn từ 2 đến 9 thêm 100 ở cây itTwo
    itTwo.update(2, 9, 100);
}