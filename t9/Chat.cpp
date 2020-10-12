#include <bits/stdc++.h>
using namespace std;
#define NAME "Chat"
ifstream fi(NAME ".inp");
ofstream fo(NAME ".out");

int main()
{
    int64_t a, n, b, ans = 1000000000000;
    fi >> n >> a >> b;
    if (b == 0)
    {
        fo << (n + a - 1) / a;
        return 0;
    }
    int64_t l = 0, r = n;
    while (l <= r)
    {
        int64_t mid = (l + r) / 2;
        if ((mid * a + mid * (mid - 1) * b) >= n)
        {
            ans = min(ans, mid);
            r = mid - 1;
        }
        else
            l = 1 + mid;
    }
    fo << ans;
}