#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Og")
#pragma GCC push_options
#pragma GCC pop_options
int n, sx, sy, dx, dy, a[10][10];
bool d[10][10];
bool check;
void visit(int x, int y)
{
    if (check == true)
        return;
    if (a[x][y] == 1 || d[x][y] == true || x <= 0 || y <= 0 || x > n || y > n)
        return;
    d[x][y] = true;
    if (x == dx && y == dy)
    {
        check = true;
        cout << "YES";
        return;
    }
    visit(x - 1, y);
    visit(x + 1, y);
    visit(x, y + 1);
    visit(x, y - 1);
}
int main()
{

    cin >> n >> sx >> sy >> dx >> dy;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];
    a[sx][sy] = 0;
    visit(sx, sy);
    if (check == false)
        cout << "NO";
}
