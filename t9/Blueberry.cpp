#include <bits/stdc++.h>
using namespace std;
#define NAME "Blueberry"

ifstream fi(NAME ".inp");
ofstream fo(NAME ".out");

int main()
{
    int n, k, ans;
    fi >> n >> k;
    ans = (n + k - 1) / k;
    if (n % k != 0 && n > 2 * k)
    {
        ans++;
    }
    if (n)
        fo << ans;
    else
        fo << 0;
}
