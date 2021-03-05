#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a1, a2, b1, b2, c1, c2;
    cin >> a1 >> b1 >> c1;
    cin >> a2 >> b2 >> c2;
    int dem1 = 0, dem2 = 0;
    if (a1 < a2)
        dem2++;
    else if (a1 > a2)
        dem1++;
    if (b1 < b2)
        dem2++;
    else if (b1 > b2)
        dem1++;
    if (c1 < c2)
        dem2++;
    else if (c1 > c2)
        dem1++;
    cout << dem1 << " " << dem2;
}