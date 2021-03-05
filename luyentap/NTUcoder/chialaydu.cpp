#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long a[1000000], x, k, n, dem = 0;
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        a[x % k] = 1;
    }
    for (int i = 0; i < k; i++)
        if (a[i] == 1)
        {
            dem++;
        }
    cout << dem;
}