#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("NewYearandNaming.inp", "r", stdin);
    int n, m;
    cin >> n >> m;
    string s[n + 10];
    string t[m + 10];
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> t[i];
    }
    int q;
    cin >> q;
    int y[q + 10];
    for (int i = 1; i <= q; i++)
    {
        cin >> y[i];
    }
    for (int i = 1; i <= q; i++)
    {
        int a = y[i] % (n);
        if (a == 0)
            a = n;
        int b = y[i] % (m);
        if (b == 0)
            b = m;
        cout << s[a] << t[b] << endl;
    }
}