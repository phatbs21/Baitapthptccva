#include <bits/stdc++.h>
using namespace std;
#define NAME "Champion"
#define tocdo cout << "Time " << clock() / (double)1000 << " sec"
ifstream fi(NAME ".inp");
ofstream fo(NAME ".out");
int main()
{
    int n, soluong = 1, so[90] = {0};
    char a, b, c;
    fi >> c;
    so[c] = 1;
    fi >> n;
    for (int i = 0; i < n; ++i)
    {
        fi >> a >> b;
        if (b == c)
        {
            c = a;
            if (so[c] == 0)
            {
                so[c] = 1;
                soluong++;
            }
        }
    }
    fo << c << "\n"
       << soluong;
    tocdo;
}
