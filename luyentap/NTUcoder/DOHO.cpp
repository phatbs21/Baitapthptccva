#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int m, n, p;
    cin >> m >> n >> p;
    p += 1;
    if (p == 60)
    {
        n += 1;
        p = 0;
    }
    if (n == 60)
    {
        m += 1;
        n = 0;
    }
    if (m == 24)
        m -= 24;
    cout << m << " " << n << " " << p;
}
