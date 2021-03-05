#include <bits/stdc++.h>
using namespace std;
long long int n, m, dem = 0;
long long int Max = 0;
long long int tong = 0;

typedef vector<vector<long long int>> vvi;
vvi a;

void loang(long long int x, long long int y, long long int c)
{
    if (x < 0 || y < 0 || x > n - 1 || y > m - 1)
        return;
    if (a[x][y] != c)
        return;
    if (a[x][y] == 0)
        return;
    a[x][y] = 0;
    dem++;
    loang(x + 1, y, c);
    loang(x, y + 1, c);
    loang(x + 1, y + 1, c);
    loang(x - 1, y + 1, c);
    loang(x - 1, y, c);
    loang(x, y - 1, c);
    loang(x - 1, y - 1, c);
    loang(x + 1, y - 1, c);
}
void tinh(long long int x, long long int y, long long int c)
{
    dem = 0;
    loang(x, y, c);
    Max = max(dem, Max);
}
int main()
{
    cin >> n >> m;
    a.resize(n + 1);
    for (long long int i = 0; i < n; i++)
        a[i].resize(m + 1);
    for (long long int i = 0; i < n; i++)
    {
        for (long long int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    for (long long int i = 0; i < n; i++)
    {
        for (long long int j = 0; j < m; j++)
        {
            if (a[i][j] != 0)
                tinh(i, j, 1);
        }
    }
    cout << Max;
}
/*
5
5
0 1 1 1 1
1 0 0 0 1
1 1 0 1 0
0 1 0 1 1
0 1 1 1 0

*/