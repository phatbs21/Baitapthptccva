#include <bits/stdc++.h>
using namespace std;
#pragma O(3)
int main()
{
    struct data
    {
        int x, y;
    };
    int n, d1 = 0, d2 = 0, d3 = 0, d4 = 0, d = 0;
    data x1[10001], x2[10001], x3[10001], x4[10001];
    freopen("bonmau.inp", "r", stdin);
    freopen("bonmau.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x, y, c;
        cin >> x >> y >> c;
        if (c == 1)
        {
            d1++;
            x1[d1].x = x;
            x1[d1].y = y;
        }
        if (c == 2)
        {
            d2++;
            x2[d2].x = x;
            x2[d2].y = y;
        }
        if (c == 3)
        {
            d3++;
            x3[d3].x = x;
            x3[d3].y = y;
        }
        if (c == 4)
        {
            d4++;
            x4[d4].x = x;
            x4[d4].y = y;
        }
    }
    for (int i = 1; i <= d1; i++)
    {
        for (int j = 1; j <= d2; j++)
        {
            for (int k = 1; k <= d3; k++)
            {
                for (int p = 1; p <= d4; p++)
                {
                    if (x1[i].y == x3[k].y && x2[j].y == x4[p].y)
                    {
                        if ((x1[i].x == x2[j].x && x3[k].x == x4[p].x) || (x1[i].x == x4[p].x && x3[k].x == x2[j].x))
                            d++;
                    }
                    if (x1[i].y == x4[p].y && x2[j].y == x3[k].y)
                    {
                        if ((x1[i].x == x2[j].x && x3[k].x == x4[p].x) || (x1[i].x == x3[k].x && x4[p].x == x2[j].x))
                            d++;
                    }
                    if (x1[i].y == x2[j].y && x3[k].y == x4[p].y)
                    {
                        if ((x1[i].x == x3[k].x && x2[j].x == x4[p].x) || (x1[i].x == x4[p].x && x3[k].x == x2[j].x))
                            d++;
                    }
                }
            }
        }
    }
    cout << d;
    return 0;
}
