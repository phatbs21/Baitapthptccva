#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int test = 1; test <= t; test++)
    {
        int a, b, l, k;
        cin >> a >> b >> l >> k;
        int n, m, p, q, r;
        cin >> n >> m >> p >> q >> r;
        int an = a * n, am = a * m, ap = a * p, ab = a * b;
        int dem = 0;
        while (an > 0 && am > 0 && ap > 0 && q > 0 && r > 0)
        {
            an -= ab * 2;
            am -= ab;
            ap -= ab;
            q -= l;
            r -= k;
            if (an >= 0 && am >= 0 && ap >= 0 && q >= 0 && r >= 0)
                dem++;
            else
                break;
        }
        cout << dem << "\n";
    }
}
//2 20 20 20
//80 80 80 10 20