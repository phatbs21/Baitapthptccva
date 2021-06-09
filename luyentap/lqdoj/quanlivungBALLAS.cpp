#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ft first
#define se second
vector<pair<int, int>> a;
int cha[10000009], hang[10000009];
vector<vector<int>> path;
int goc(int u)
{
    if (cha[u] == u)
        return u;
    cha[u] = goc(cha[u]);
    return cha[u];
}
bool join(int u, int v)
{
    u = goc(u);
    v = goc(v);
    if (u == v)
        return false;
    if (hang[u] == hang[v])
        hang[u]++;
    if (hang[u] < hang[v])
    {
        cha[u] = v;
        path[v].push_back(u);
    }
    else
    {
        cha[v] = u;
        path[u].push_back(v);
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("quanlivungbs.inp", "r", stdin);
#endif
    int n, m;
    cin >> n >> m;
    a.resize(m);
    path.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        a[i].ft = x;
        a[i].se = y;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i <= n; i++)
    {
        cha[i] = i;
        hang[i] = 0;
    }
    int mst = n;
    int dem = 0;
    //sort(a.begin(), a.end());
    for (int i = 0; i < m; i++)
    {
        if (dem == n - 1)
            break;
        if (join(a[i].ft, a[i].se))
        {
            mst--;
            dem++;
        }
    }
    cout << mst << "\n";

    vector<int> vt;
    for (int i = 1; i <= n; i++)
    {
        if (cha[i] == i)
        {
            vt.push_back(i);
        }
    }
    for (int i = 0; i < vt.size(); i++)
    {
        int u = vt[i];
        queue<int> as;
        as.push(u);
        for (int j = 0; j < path[u].size(); j++)
        {
            if (cha[path[u][j]] == u)
                as.push(path[u][j]);
        }
        cout << as.size() << " ";
        while (!as.empty())
        {
            cout << as.front() << " ";
            as.pop();
        }
        cout << endl;
    }
    /*for (int i = 1; i <= n; i++)
    {
        if (cha[u])
    }*/
}
//vector<int> a[100005];
//vector <vector<int>> a;
//a.assign(n+1,vector<int>(n+1,0));