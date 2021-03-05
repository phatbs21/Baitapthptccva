#include <bits/stdc++.h>
using namespace std;
int a[100 + 1][100 + 1];
void visit(int u, int n)
{
    static bool d[1000];
    cout << "Di den dinh " << u << endl;
    d[u] = true;
    for (int v = 1; v <= n; v++)
    {
        if (a[u][v] > 0 && d[v] == false)
            visit(v, n);
    }
}
int main()
{
    int i, j, n;
    freopen("DFS.inp", "r", stdin);
    cin >> n;

    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    visit(11, n);
}
