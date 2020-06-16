#include <iostream>
using namespace std;

int main()
{
    const int dx[4] = {1, 0, -1, 0};
    const int dy[4] = {0, 1, 0, -1};
    int x, y;
    int xx = 0, yy = 0, t = 0, kq = 1;
    cin >> x >> y;
    while ((x != xx) || (y != yy))
    {
        kq++;
        if ((((xx != 0) && (xx == yy)) || (xx > 0) && (xx + yy == 1)) || ((yy > 0) && (xx + yy == 0)))
            t = (t + 1) % 4;
        xx += dx[t];
        yy += dy[t];
    }
    cout << kq;
    return 0;
}