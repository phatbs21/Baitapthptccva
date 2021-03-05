#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
vector<int> ql[N], qid[N], tree(N);
int n, q;

void update(int id, int val)
{
    while (id <= n)
    {
        tree[id] += val;
        id += (id & -id);
    }
}
int query(int id)
{
    int ans = 0;
    while (id > 0)
    {
        ans += tree[id];
        id -= (id & -id);
    }
    return ans;
}
int get(int l, int r)
{
    return query(r) - query(l - 1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> q;
    int l, r, x;
    int c[n + 1], a[n + 1] = {0}, ans[q];
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
    }

    for (int i = 0; i < q; i++)
    {
        cin >> l >> r;
        ql[r].push_back(l);
        qid[r].push_back(i);
    }   

    for (int i = 1; i <= n; i++)
    {
        if (a[c[i]] > 0)
            update(a[c[i]], -1);
        update(i, 1);
        a[c[i]] = i;

        for (int j = 0; j < ql[i].size(); j++)
        {
            ans[qid[i][j]] = get(ql[i][j], i);
        }
    }

    for (int i = 0; i < q; i++)
        cout << ans[i] << "\n";
}