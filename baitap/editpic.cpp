#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int tile = 1, w, l, a, b;
    cin >> l >> w;
    while ((tile <= w) || (tile <= l))
    {
        tile = tile * 2;
    }
    do
    {
        tile = tile / 2;
        a = (tile / 5) * 4;
        b = (tile / 4) * 5;
    } while ((a > l) || (a > w));
    if (l < w && l < b)
        if (l < tile)
        {
            w = tile;
        }
        else
        {
            l = tile;
            if (b < w)
            {
                w = b;
            }
        }
    else if (l < w && l >= b)
    {
        l = b;
        w = tile;
    }
    else
    {
        if (w < tile)
            l = tile;
        else
        {
            w = tile;
            if (l > b)
            {
                l = b;
            }
        }
    }
    cout << l << " " << w;
}
