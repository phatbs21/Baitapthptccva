#include <bits/stdc++.h>
using namespace std;
#define NAME "password"
#define tocdo cout << "Time " << clock() / (double)1000 << " sec"
ifstream fi(NAME ".inp");
ofstream fo(NAME ".out");

int main()
{
    int n, tong = 0;
    string s;
    fi >> s;
    fi >> n;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] + n - 97 > 25)
        {
            tong += (s[i] - 97 - 25 + n - 1);
        }
        else
        {
            tong += (s[i] + n - 97);
        }
    }
    fo << tong;
}