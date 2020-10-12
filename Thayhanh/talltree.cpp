#include <bits/stdc++.h>
using namespace std;
#define NAME "talltree"
#define tocdo cout << "Time " << clock() / (double)1000 << " sec"
ifstream fi(NAME ".inp");
ofstream fo(NAME ".out");
#define mod 998244353

#define N 300300
vector<int> p[500001];
int par[N];
int high[N];
long long sum[500001];
string s;
int n, t, q, v, l, k, x, y;
int n;
vector<int> adj[N];

int h[1001];                          //lưu giá trị vị trí
int a[1001] = {0, 1, 3, 5, 7, 9, 11}; // lưu giá trị

void build(int v, int l, int r)
//nút v quản lí đoạn từ l..r
{
    if (l == r)
    {
        h[v] = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(2 * v, l, mid);
    build(2 * v + 1, mid + 1, r);
    h[v] = h[2 * v] + h[2 * v + 1];
    return;
}
int getsum(int v, int l, int r, int p, int q)
//tính tổng trên đoạn p..q riêng trên nhánh do nút v quản lí trên đoạn l..r
//độ phức tạp O(log n)
{
    if (q < l || r < p)
        return 0;
    if (p <= l && r <= q)
        return h[v];
    int mid = (l + r) / 2;
    return getsum(2 * v, l, mid, p, q) + getsum(2 * v + 1, mid + 1, r, p, q);
}
void update(int v, int l, int r, int i, int x)
//cập nhật giá trị a[i]=x trên nhánh v để quản lí đoạn l..r
//độ phức tạp O(log n)
{
    if (i < l && i > r)
        return;
    if (l == r)
        h[v] = x;
    int mid = (l + r) / 2;
    update(2 * v, l, mid, i, x);
    update(2 * v + 1, mid, r, i, x);
    return;
}

void prepare(void)
{
    dfs(1);
    high[0] = -1;

        for (int i = 1; i <= n; i++)
        {
            par[i] = par[par[i]];
        }
    
}

void sub2()
{
    cin >> q;
    queue<pair<int, int>> que;
    que.push({1, 0});
    while (!que.empty())
    {
        x = que.front().first;
        y = que.front().second + 1;
        que.pop();
        for (int i = 0; i < p[x].size(); i++)
        {
            high[p[x][i]] = y;
            que.push({p[x][i], y});
        }
    }
    while (q--)
    {
        cin >> s;
        if (s == "add")
        {
            cin >> v >> k >> l;
            sum[v] = ((long long)sum[v] + k) % mod;
        }
        else
        {
            int d = sum[v];
            cin >> v;
            if (s == "get")
            {
                cout << (sum[v] * high[v]) % mod;
            }
            else
            {
                queue<int> que;
                que.push(v);
                while (!que.empty())
                {
                    x = que.front();
                    que.pop();
                    for (int i = 0; i < p[x].size(); i++)
                    {
                        d = (sum[v] + d) % mod;
                        que.push(p[x][i]);
                    }
                }
                cout << d << " ";
            }
        }
    }
}

int main()
{
    build(1, 1, n);
    getsum(1, 1, n, 1, n);
    update(1, 1, n, 2, 9);

    int t;
    cin >> t >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> par[i];
        p[par[i]].push_back(i + 1);
    }
    cin >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> s;
        if (s == "add")
        {
        }
        else if (s == "get")
        {
            
        }
        else 
        {

        }
    }
}
//877E
