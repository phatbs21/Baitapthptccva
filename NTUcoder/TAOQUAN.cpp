#include <bits\stdc++.h>
using namespace std;
int main()
{
    int n, m, k, q;
    cin >> n >> m >> k;
    q = n % 2;
    n = n - q;
    if (n / 2 > m)
    {
        q = q + n - m * 2;
        n = m * 2;
    }
    else
    {
        q = q + m - n / 2;
        m = n / 2;
    }
    while (k > q && m > 0)
    {
        m--;
        q += 3;
    }
    cout << m;
}