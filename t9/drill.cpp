#include "bits/stdc++.h"
#define NAME "drill."
using namespace std;
ifstream fi(NAME "inp");
ofstream fo(NAME "out");
#define ll int64_t
const ll INFL = 1e18;
int main()
{
    int n, k;
    fi >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        fi >> a[i];
    ll best = INFL;
    for (int i = -1; i <= 1; i += 2)
    {
        vector<int> tmp = a;
        for (int j = 0; j < n; j += 2)
            tmp[j] += k * i;
        auto tmp2 = tmp;
        ll sum = 0;
        nth_element(tmp.begin(), tmp.begin() + tmp.size() / 2, tmp.end());
        int val = tmp[tmp.size() / 2];
        for (int num : tmp)
            sum += abs((ll)num - val);
        if (sum < best)
            best = sum;
    }
    fo << best << "\n";
    cout << "\nTime: " << clock() / (double)1000 << " sec";
}