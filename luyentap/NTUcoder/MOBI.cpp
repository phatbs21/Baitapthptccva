#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    long long n, k, chiso = 0;
    cin >> n >> k;
    vector<long long> a(3000000, 0);

    for (long long i = 0; i < n; i++)
    {
        long long x, y;
        cin >> x >> y;
        a[x] = y;
        if (x > chiso)
            chiso = x;
    }
    for (long long i = 1; i <= chiso; i++)
    {
        a[i] += a[i - 1];
    }
    long long dem = 0, Max = 0;
    if (2 * k > chiso)
    {
        cout << a[chiso];
        return 0;
    }
    for (long long i = k + 1; i <= chiso - k; i++)
    {
        dem = a[i + k] - a[i - k - 1];
        if (dem > Max)
            Max = dem;
    }
    cout << Max;
    return 0;
}