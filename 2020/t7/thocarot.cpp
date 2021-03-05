#include <bits/stdc++.h>
using namespace std;
int a[100][100];
bool kt = false;
int dem = 0;
int n, m;
void loang(int x, int y)
{
    if (a[x][y] == 2)
    {
        cout << "co the an ca rot";
        kt = true;
    }
    if (a[x][y] == 1)
    {
        dem++;
        a[x][y] = 0;
        if (x > 1)
            loang(x - 1, y);
        if (y > 1)
            loang(x, y - 1);
        if (x < n)
            loang(x + 1, y);
        if (y < m)
            loang(x, y + 1);
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }
    loang (1,1);
    if (kt==false)
    {
        cout<<" khong the an cu ca rot";
    }
}