#include <bits/stdc++.h>
using namespace std;
#define NAME "Equation"

ifstream fi(NAME ".inp");
ofstream fo(NAME ".out");

int main()
{
    int t, n, ans, r;
    fi >> t;
    for (int i = 0; i < t; i++)
    {
        r = 0;
        fi >> n;
        /*
        tinh so luong bit 1
        Cach 1:
        for (int i = 30; i >= 0; i--)
        {
            r += (n >> i) & 1;
        }
        ans = 1 << r;
        */
        //C2
        ans = 1 << __builtin_popcount(n);
        //END
        fo << ans << "\n";
    }
}