#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1), f(n + 1, INT_MAX);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    a[0] = a[1];
    f[0] = 0;
    f[1] = 0;
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