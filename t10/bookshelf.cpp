#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("bookshelf.inp", "r", stdin);
    //freopen("bookshelf.out", "w", stdout);
    int n, l;
    cin >> n >> l;
    int h[100000], w[100000];
    for (int i = 1; i <= n; i++)
    {
        cin >> h[i] >> w[i];
    }
    int f[100000];
    for (int i = 1; i <= n; i++)
    {
        f[i] = INT_MAX;
        int day = 0, cao = 0;
        for (int j = i; j >= 1; j--)
        {
            day += w[j];
            if (day > l)
                break;
            cao = max(cao, h[j]);
            f[i] = min(f[i], f[j - 1] + cao);
        }
    }
    cout << f[n];
}