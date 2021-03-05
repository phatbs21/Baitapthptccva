#include <bits/stdc++.h>

using namespace std;
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Og")
#pragma GCC push_options
#pragma GCC pop_options

int main()
{
    freopen("AB.INP", "r", stdin);
    freopen("AB.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    getline(cin, s);
    int n = s.length();
    int c[n+100];
    int tong = 0, dem = 0, h = 0;
    for (int i = 1; i <= n + 100; i++)
        c[i] = 0;
    c[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (s[i] == 'A')
            h = h + 1;
        else if (s[i] == 'B')
            h = h - 1;
        dem = dem + c[h];
        c[h] += 1;
    }
    cout << dem << endl;
}
