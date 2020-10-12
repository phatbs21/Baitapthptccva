#include <bits/stdc++.h>
using namespace std;
#define NAME "data"
#define tocdo cout << "Time " << clock() / (double)1000 << " sec"
ifstream fi(NAME ".inp");
ofstream fo(NAME ".out");
int main()
{
    int n, x, dem = 0, i = 0;
    fi >> n >> x;
    vector<int> a(n);
    for (auto &i : a)
        fi >> i;
    sort(a.begin(), a.end());
    while (n > i)
    {
        n--;
        if (a[n ] > x || a[n] + a[i] > x)
        {
            dem++;
            continue;
        }
        i++;
        dem++;
    }
    if (n == i)
    {
    }
    fo << dem;
}