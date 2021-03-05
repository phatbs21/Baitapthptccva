#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    a[0] = a[1];
    vector<int> f(n + 1, INT_MAX);
    f[1] = 0;
    f[0] = 0;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= k; j++)
        {
            if (i - j >= 0)
            {
                f[i] = min(f[i - j] + abs(a[i] - a[i - j]), f[i]);
            }
        }
    }
    cout << f[n];
}