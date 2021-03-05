#include <bits/stdc++.h>
using namespace std;
long long mu(long long n,long long x)
{
    long long tong = 1;
    while (n > 0)
    {
        if (n & 1)
            tong = (x * tong) % 20122007;
        n = n / 2;
        x = (x * x) % 20122007;
    }
    return tong;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long a;
    long long kq = 1;
    cin >> a;
    for (long long i = 1; i * i <= a; i++)
        if (a % i == 0)
        {
            if (a / i != i)
            {
                kq = kq * (mu(a / i, 3) - 1) % 20122007;
            }
            kq = kq * (mu(i, 3) - 1) % 20122007;
        }
    cout << kq;
    return 0;
}