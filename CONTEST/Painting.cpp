#include <bits/stdc++.h>
using namespace std;
int main()
{
    int h, w, n;
    cin >> h >> w >> n;
    int max, min;
    if (h >= w)
    {
        max = h;
        min = w;
    }
    else
    {
        min = h;
        max = w;
    }

    int tong = 0;
    for (int i = 1; i <= min; i++)
    {
        tong += max;
        if (tong >= n)
        {
            cout << i;
            return 0;
        }
    }
}