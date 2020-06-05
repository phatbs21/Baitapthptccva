#include <bits/stdc++.h>
using namespace std;
int a[100] = {1, 1}, b[100] = {1, 0};
int thu(int n, int k)
{
    if (n <= 1)
    {
        return b[n];
    }
    if (k <= a[n - 2])
    {
        return thu(n - 2, k);
    }
    return thu(n - 1, k - a[n - 2]) + b[n - 2];
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, t;
    for (int i = 2; i <= 45; i++)
    {
        a[i] = a[i - 1] + a[i - 2];
        b[i] = b[i - 1] + b[i - 2];
    }
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        cout << thu(n, m) << endl;
    }
}
