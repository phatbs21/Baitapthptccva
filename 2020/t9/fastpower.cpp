#include <bits/stdc++.h>
using namespace std;
#define NAME "fastpower"
ifstream fi(NAME ".inp");
ofstream fo(NAME ".out");
int64_t a, n, p, ans = 1;
int64_t fastpow(int64_t a, int64_t n)
{
    if (n == 0)
        return 1;
    if (n & 1)
        return fastpow(a, n - 1) * a;
    else
    {
        int64_t b = fastpow(a, n / 2);
        return b * b;
    }
}
int main()
{
    fi >> a >> n >> p;
    a %= p;
    while (n)
    {
        if (n & 1)
            ans = (ans * a) % p;
        a = (a * a) % p;
        n >>= 1;
    }
    fo << ans;
}