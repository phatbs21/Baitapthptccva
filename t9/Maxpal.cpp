#include <bits/stdc++.h>
using namespace std;
#define NAME "Maxpal"
#define tocdo cout << "Time " << clock() / (double)1000 << " sec"
ifstream fi(NAME ".inp");
ofstream fo(NAME ".out");
int q, k, so[26] = {0};
int64_t ans;
string s;
int main()
{
    fi >> s;
    q = s.size();
    for (int i = 0; i < q; ++i)
        ++so[s[i] - 97];
    for (int i = 0; i < 26; ++i)
        ans += (int64_t)so[i] * (so[i] + 1) / 2;
    fo << ans;
    tocdo;
}