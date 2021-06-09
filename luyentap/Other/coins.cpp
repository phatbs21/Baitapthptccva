#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int q = min(a, b), w = max(a, b), lan1 = c / q, lan2 = 0, maxx = INT_MIN;
    while (lan1 >= 0)
    {
        while (q * lan1 + w * lan2 < c)
        {
            lan2++;
        }
        if (q * lan1 + w * lan2 > c)
            lan2--;
        if (q * lan1 + w * lan2 == c)
            maxx = max(maxx, lan1 + lan2);
        lan1--;
    }
    if (maxx != INT_MIN)
        cout << maxx;
    else
        cout << -1;
}
// 