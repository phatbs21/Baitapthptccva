#include <bits/stdc++.h>
using namespace std;
#define NAME "scramble"
#define tocdo cout << "Time " << clock() / (double)1000 << " sec"
ifstream fi(NAME ".inp");
ofstream fo(NAME ".out");

int main()
{
    int64_t n, tong = INT_MIN;
    fi >> n;
    for (int64_t i = 1; i <= n; i++)
    {
        int64_t temp;
        fi >> temp;
        if (temp > 100000)
            continue;
        tong = max(tong, temp);
    }
    fo << tong;
}