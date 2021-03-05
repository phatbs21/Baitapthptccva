#include <bits/stdc++.h>
using namespace std;
long a[100100], b[100100];
long n, d, tong, c;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    b[n + 1] = 10000 * 100000 + 1;  
    for (long i = 1; i <= n; i++)
    {
        cin >> a[i];
        d = d + a[i];
        c += a[i];
        b[n + 1] = min(b[n + 1], c);
    }
    if (d <= 0)
    {
        cout << "0";
        return 0;
    }
    if (b[n + 1] > 0)
        tong++;
    for (long i = n; i >= 2; i--)
    {
        b[i] = min(b[i + 1] + a[i], a[i]);
        tong += (b[i] > 0);
    }
    cout << tong;
}