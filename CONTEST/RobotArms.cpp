#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Og")
#pragma GCC push_options
#pragma GCC pop_options
struct RA
{
    long long int x, l;
};
bool cmp(RA X, RA Y)
{
    if (X.x == Y.x)
        return X.l < Y.l;
    return X.x < Y.x;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long int n;
    cin >> n;
    RA f[n + 1];
    for (long long int i = 1; i <= n; i++)
    {
        cin >> f[i].x >> f[i].l;
    }
    long long int dem = n;
    bool d[n + 1];
    for (long long int i = 1; i <= n; i++)
        d[i] = false;
    sort(f + 1, f + n + 1, cmp);
    for (long long int i = 1; i < n; i++)
    {
        if (d[i] == true)
            continue;
        for (long long int j = i + 1; j <= n; j++)
        {
            if (d[j] != true)
            {
                if ((f[i].x + f[i].l >= f[j].x))
                {
                    dem--;
                    d[j] = true;
                }
                else if (f[i].x - f[i].l > 0 && f[i].x - f[i].l >= f[j].x)
                {
                    dem--;
                    d[j] = true;
                }
            }
        }
    }
    cout << dem;
}