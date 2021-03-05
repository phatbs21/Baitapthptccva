//https://vjudge.net/problem/Aizu-ALDS1_12_A?fbclid=IwAR3dFvpkxbMmi_U3Jm3zO1RxWHKQfivpW34TM-iMOFfcnWT6PlXmJuVmkq4
#include <bits/stdc++.h>
using namespace std;
struct MinimumSpanningTree
{
    int u, v, w;
};
bool cmp(MinimumSpanningTree a, MinimumSpanningTree b)
{
    return a.w < b.w;
}

int cha[3000], hang[3000];

int find(int u)
{
    if (cha[u] != u)
        cha[u] = find(cha[u]);
    return cha[u];
}

bool join(int u, int v)
{
    u = find(u);
    v = find(v);
    if (u == v)
        return false;
    if (hang[u] == hang[v])
        hang[u]++;
    if (hang[u] < hang[v])
        cha[u] = v;
    else
        cha[v] = u;
    return true;
}

int main()
{
    //freopen("MinimumSpanningTree.inp", "r", stdin);
    int n ;
    cin >> n;
    int a[n+1][n+1];
    MinimumSpanningTree b[3000];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cha[i] = i;
        hang[i] = 0;
    }

    int z = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (a[i][j] == -1)
            {
                continue;
            }
            else
            {
                b[z].v = i;
                b[z].u = j;
                b[z].w = a[i][j];
                z++;
            }
        }
    }
    z--;
    sort(b + 1, b + z + 1, cmp);
    int x, y, tong = 0;
    for (int i = 1; i <= z; i++)
    {
        if (join(b[i].u, b[i].v))
        {
            tong += b[i].w;
        }
    }
    cout << tong<<endl;
}