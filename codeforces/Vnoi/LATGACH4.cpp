#include <bits/stdc++.h>
using namespace std;
uint64_t n, a, ans, fib, t[4] = {0, 1, 1, 1}, r[4] = {0, 1, 1, 1}, tg[4], p = 111539786;
void mp2(uint64_t x[], uint64_t y[], uint64_t z[])
{
    tg[0] = (x[0] * y[0] + x[1] * y[2]) % p;
    tg[1] = (x[0] * y[1] + x[1] * y[3]) % p;
    tg[2] = (x[2] * y[0] + x[3] * y[2]) % p;
    tg[3] = (x[2] * y[1] + x[3] * y[3]) % p;
    z[3] = tg[3];
    z[2] = tg[2];
    z[1] = tg[1];
    z[0] = tg[0];
}
int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        t[0] = 0, t[1] = 1, t[2] = 1, t[3] = 1;
        r[0] = 0, r[1] = 1, r[2] = 1, r[3] = 1;
        cin >> n;
        while (n)
        {
            if (n & 1)
                mp2(r, t, r);
            mp2(t, t, t);
            n >>= 1;
        }
        ans = r[2] % p;
        cout << ans << endl;
    }
}