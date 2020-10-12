#include <bits/stdc++.h>
using namespace std;
#define NAME "triprime"
#define tocdo cout << "Time " << clock() / (double)1000 << " sec"
ifstream fi(NAME ".inp");
ofstream fo(NAME ".out");
int main()
{
    int n;
    fi >> n;
    int dem;
    int z = 0;

    for (int i = 2; i <= sqrt(n) + 1; i++)
    {
        dem = 0;
        while (n % i == 0)
        {
            ++dem;
            n /= i;
        }
        if (dem)
        {
            if (dem > 1)
            {
                fo << "NO";
                return 0;
            }
            if (n > i)
            {
                z++;
            }
        }
    }
    if (z != 2)
    {
        fo << "NO";
    }
    else
        fo << "YES";
}