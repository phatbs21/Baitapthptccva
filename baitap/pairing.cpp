#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("PAIRING.INP","r",stdin);
    freopen("PAIRING.OUT","w",stdout);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (d == b)
    {
        cout << a % 2 + c % 2;
    }
    else
    {
        cout << a % 2 + c % 2 +abs(b-d);
    }
}