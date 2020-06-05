#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n, m;
    cin >> n >> m;
    long long int a[500], f[500];
    memset(a, 0, sizeof(a));
    memset(f, 0, sizeof(f));

    for (long long int i = 1; i <= m; i++)
    {
        cin >> a[i];
    }
    f[0] = 1;
    for (long long int i = 1; i <= m; i++)
    {
        for (long long int j = 1; j <= n; j++)
        {
            if (j >= a[i])
            {
                f[j] += f[j - a[i]];
            }
        }
    }
    cout << f[n];
}