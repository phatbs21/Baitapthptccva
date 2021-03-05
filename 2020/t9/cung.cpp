#include <bits/stdc++.h>
using namespace std;
int n, n2, u, ux = 0, v, t, t1, t2;
vector<int> b, c, d;
ifstream fi("cung.inp");
ofstream fo("cung.out");

void insert_fw(vector<int> &a, int x)
{
    while (x <= n2)
    {
        a[x]++;
        x += (x & (-x));
    }
}
int sum_fw(vector<int> &a, int x)
{
    int tg = 0;
    while (x > 0)
    {
        tg += a[x];
        x &= (x - 1);
    }
    return (tg);
}
void update_fw(vector<int> &a, int x)
{
    while (x <= n2)
    {
        a[x]--;
        x += (x & (-x));
    }
}
int main()
{
    fi >> n;
    n2 = n << 1;
    b.assign(n2 + 1, 0);
    c.assign(n2 + 1, 0);
    d.assign(n2 + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        fi >> u >> v;
        if (u > v)
            swap(u, v);
        if (u > ux)
        {
            ux = u;
            d[u] = v;
        }
        insert_fw(b, u);
        insert_fw(c, v);
    }
    int res = 0;
    for (int i = 1; i <= ux; i++)
    {
        if (!d[i])
            continue;
        t = sum_fw(b, d[i]) - sum_fw(c, d[i]);
        res += t;
        update_fw(b, i);
        update_fw(c, d[i]);
    }
    fo << res;
    cout << "Time " << clock() / (double)1000 << " sec";
}