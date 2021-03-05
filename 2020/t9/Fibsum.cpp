#include <bits/stdc++.h>
using namespace std;
#define NAME "Fibsum"
ifstream fi(NAME ".inp");
ofstream fo(NAME ".out");
const int p = (int)1e9;
vector<int64_t> x(4), y(4), z(4);
vector<int64_t> mult(vector<int64_t> a, vector<int64_t> b)
{
    vector<int64_t> t(4);
    t[0] = (a[0] * b[0] + a[1] * b[2]) % p;
    t[1] = (a[0] * b[1] + a[1] * b[3]) % p;
    t[2] = (a[2] * b[0] + a[3] * b[2]) % p;
    t[3] = (a[2] * b[1] + a[3] * b[3]) % p;
    return t;
}
int64_t get_fib(int k)
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
    int a, b;
    int64_t ans;
    while (!fi.eof())
    {
        a = -1;
        fi >> a >> b;
        if (a == -1)
            break;
        if (a == b)
            ans = (a == 0) ? 1 : get_fib(a);
        else
            ans = (get_fib(b + 2) + p - get_fib(a + 1)) % p;
        fo << ans << "\n";
    }
}