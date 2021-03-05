#include <bits/stdc++.h>
using namespace std;
#define NAME "Indzone"
ifstream fi(NAME ".inp");
ofstream fo(NAME ".out");
const int64_t p = 998244353;
vector<int64_t> x(4), y(4), z(4);
vector<int64_t> mult(vector<int64_t> a, vector<int64_t> b)
{
    vector<int64_t> t(4);
    t[0] = (a[0] * b[0] % p + a[1] * b[2] % p) % p;
    t[1] = (a[0] * b[1] % p + a[1] * b[3] % p) % p;
    t[2] = (a[2] * b[0] % p + a[3] * b[2] % p) % p;
    t[3] = (a[2] * b[1] % p + a[3] * b[3] % p) % p;
    return t;
}
int64_t get_fib(int64_t k)
{
    z[0] = z[3] = 1;
    z[1] = z[2] = 0;
    x[0] = x[1] = x[2] = 1;
    x[3] = 0;
    while (k > 0)
    {
        if (k & 1)
            z = mult(x, z);
        x = mult(x, x);
        k >>= 1;
    }
    return z[0];
}
int main()
{
    int64_t n;
    fi >> n;
    fo << get_fib(n) % p * get_fib(n + 1) % p;
}