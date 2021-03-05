#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int dem = 0;
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        if (x1 != x2 && y1 != y2)
        {
            dem = abs(x2 - x1) + abs(y2 - y1) + 2;
        }
        else if (x1 == x2)
        {
            dem = abs(y2 - y1);
        }
        else if (y1 == y2)
        {
            dem = abs(x2 - x1);
        }
        else
        {
            dem = 0;
        }
        cout << dem << "\n";
    }
}