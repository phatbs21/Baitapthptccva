#include <bits/stdc++.h>
using namespace std;
#define NAME "sumnum"
#define tocdo cout << "Time " << clock() / (double)1000 << " sec"
ifstream fi(NAME ".inp");
ofstream fo("sunmum.out");

int main()
{
    int64_t t;
    fi >> t;
    int64_t n;
    while (fi >> n)
    {
        vector<int64_t> a(n);
        for (auto &i : a)
        {
            fi >> i;
        }
        fo << accumulate(a.begin(), a.end(), 0) << "\n";
    }
}
