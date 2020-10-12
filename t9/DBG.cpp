#include <bits/stdc++.h>
using namespace std;
#define NAME "DBG"

ifstream fi(NAME ".inp");
ofstream fo(NAME ".out");

int main()
{
    int n, m, k;
    fi >> n;
    for (int i = 0; i < 32; i++)
    {
        if ((1 << i) > n)
        {
            fo << i << "\n";
            m = i;
            break;
        }
    }
    for (int i = 0; i < m; i++)
    {
        k = 0;
        for (int p = 1; p < n; ++p)
            k += (p >> 1) & 1;
        fo << k-1 << ' ';
        for (int p = 1; p < n; ++p)
        {
            if (p & (1 << i))
                fo << p + 1 << ' ';
        }
        fo << "\n";
    }
    cout << "Time:" << clock() / (double)1000 << " sec";
}