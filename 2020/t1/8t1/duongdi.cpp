#include <bits/stdc++.h>
using namespace std;
int s, t;
int a[100 + 1][100 + 1];
bool stop = false;
int T[1000];

void viet()
{
    int p[1000], z = 1;
    int i = t;
    while (i != s)
    {
        p[z] = i;
        z++;
        i = T[i];
    }
    p[z] = s;
    for (i = z; i >= 1; i--)
        cout << p[i] << " ";
    cout << endl;
}
void visit(int u, int n)
{
    if (stop == true)
        return;
    static bool d[1000];
    d[u] = true;
    for (int v = 1; v <= n; v++)
    {
        if (a[u][v] > 0 && d[v] == false)
        {
            T[v] = u;
            d[v]=true;
            if (v == t)
            {
                viet();
                stop = true;
                return;
            }
            visit(v, n);
        }
    }
    return;
}
int main()
{
    int i, j, n;
    freopen("duongdi.inp", "r", stdin);
    cin >> n;
    cin >> s >> t;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }
    visit(s, n);
}

0 1 1 1 0 0 0 0 0 0 0
1 0 0 0 1 1 0 0 0 0 0
1 0 0 0 0 1 1 0 0 0 0 
1 0 0 0 0 0 1 1 0 0 0
0 1 0 0 0 0 0 0 1 0 0
0 1 1 0 0 0 0 0 1 1 0
0 0 1 1 0 0 0 0 0 1 1 
0 0 0 1 0 0 0 0 0 0 1
0 0 0 0 1 1 0 0 0 0 0
0 0 0 0 0 1 1 0 0 0 0 
0 0 0 0 0 0 1 1 0 0 0