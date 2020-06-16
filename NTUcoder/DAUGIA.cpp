#include <bits/stdc++.h>
using namespace std;
int a, b, d;
bool kt(int x)
{
    int n;
    n = x;
    if (n < 2)
        return false;
    if (n < 4)
        return true;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            return false;
    return true;
}
bool doixung(int x)
{
    int n, a, t;
    n = x;
    t = 0;
    while (n > 0)
    {
        a = n % 10;
        n = n / 10;
        t = t * 10 + a;
    }
    if (t == x)
        return true;
    return false;
}
int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b;
    for (int i = a; i <= b; i++)
        if ((kt(i)) && (doixung(i)))
            d++;
    cout << d;
}
