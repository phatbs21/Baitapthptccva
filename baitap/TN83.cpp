#include <bits/stdc++.h>

using namespace std;
int n, i, tmp, res;
int a[300001];
int main()
{
    freopen("TN83.inp", "r", stdin);
    freopen("TN83.out", "w", stdout);
    cin >> n;
    for (i = 1; i <= n; i++) cin >> a[i];
    sort(a+1, a+n+1);
    tmp = a[n]+1;
    for (i = 1; i <= n; i++) if (a[i]+n >= tmp) res++;
    cout << res;
}
