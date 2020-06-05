#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n + 1], b[n + 1];
    memset(b, 0, sizeof(b));
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        b[i] = a[i] + b[i - 1];
    }
    int m;
    cin >> m;
    int p[m + 1];
    for (int i = 1; i <= m; i++)
    {
        cin >> p[i];
        cout << lower_bound(b + 1, b + n + 1, p[i]) - b << " ";
    }
}
