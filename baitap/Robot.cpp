#include <bits/stdc++.h>

using namespace std;

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Og")
#pragma GCC push_options
#pragma GCC pop_options

#define toida INT_MAX
#define toithieu INT_MIN

int a[100 + 1][100 + 1];
bool stop = false;
int T[1000];

bool coduong(int i, int j);
bool check(int k);

int main()
{
    int n, d = 0, c = 110, k = 0;
    int g = (d + c) / 2;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("robot.inp", "r", stdin);
    freopen("robot.out", "w", stdout);
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    while (d <= c)
    {
        if (check(g))
        {
            c = g - 1;
            k = g;
        }
        else
        {
            d = k + 1;
        }
    }
    cout << k;
}

bool check(int k)
{
    for (int x = 0; x <= (110 - k); x++)
    {
        if (coduong(x, x + k))
            return true;
    }
    return false;
}


bool coduong(int i, int j)
{

    if (stop == true)
        return true;
    static bool d[1000];
    d[i] = true;
    for (int v = 1; v <= j; v++)
    {
        if (a[i][v] > 0 && d[v] == false)
        {
            T[v] = i;
            d[v] = true;
            if (v == n)
            {
                stop = true;
                return true;
            }
            coduong(v, j);
        }
        return false;
    }
}
