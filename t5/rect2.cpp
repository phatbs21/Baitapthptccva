#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
    if ((x1 - x2) * (x1 - x3) == -(y1 - y2) * (y1 - y3))
    {
        cout << x2 + x3 - x1 << " " << y2 + y3 - y1;
    }
    else if ((x2 - x1) * (x2 - x3) == -(y2 - y1) * (y2 - y3))
    {
        cout << x1 + x3 - x2 << " " << y1 + y3 - y2;
    }
    else
    {
        cout << x1 + x2 - x3 << " " << y1 + y2 - y3;
    }
    return 0;
}
