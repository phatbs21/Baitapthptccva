#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, a[1000], dem = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n, greater<int>());
    dem += a[0];
    for (int i = 1; i < n; i++)
    {
        a[i] = a[i] - i;
        if (a[i] > 0)
        {
            dem = dem + a[i];
        }
    }
    cout << dem;
    return 0;
}