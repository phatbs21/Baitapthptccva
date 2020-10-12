#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int q = d;
    if (q >= (a + b + c))
    {
        cout << a << " " << b << " " << c;
    }
    else
    {
        if (a = min(min(a, b), c))
        {
            q -= a;
            if (q < 0)
            {
                cout << d << " 0 0";
                return 0;
            }
        }
        else if (b = min(min(a, b), c))
        {
            q -= b;
            if (q < 0)
            {
                cout << d << " 0 0";
                return 0;
            }
        }
        else if (c = min(min(a, b), c))
        {
            q -= c;
            if (q < 0)
            {
                cout << d << " 0 0";
                return 0;
            }
        }
        d = q;
        const int z = min(min(a, b), c);
        if (a = min(max(a, b), c))
        {
            q -= a;
            if (q < 0)
            {
                cout << z << " " << d << " 0";
                return 0;
            }
        }
        else if (b = min(max(a, b), c))
        {
            q -= b;
            if (q < 0)
            {
                cout << z << " " << d << " 0";
                return 0;
            }
        }
        else if (c = min(max(a, b), c))
        {
            q -= c;
            if (q < 0)
            {
                cout << z << " " << d << " 0";
                return 0;
            }
        }
        int x = min(max(a, b), c);
        cout << z << " " << x << " " << q;
        return 0;
    }
}