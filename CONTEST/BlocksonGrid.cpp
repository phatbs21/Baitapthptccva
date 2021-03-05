#include <bits/stdc++.h>
using namespace std;
int main()
{
    int h, w, a[101][101];
    cin >> h >> w;
    int Min = INT_MAX;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            cin >> a[i][j];
            if (a[i][j] < Min)
            {
                Min = a[i][j];
            }
        }
    }
    int tong = 0;
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            tong += a[i][j] - Min;
        }
    }
    cout << tong;
}