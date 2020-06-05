#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("MK.inp", "r", stdin);
    freopen("MK.out", "w", stdout);
    int n, dem = 0;
    cin >> n;
    string s[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                continue;
            if (s[j].find(s[i]) != std::string::npos)
            {
                dem++;
            }
        }
    }
    cout << dem;
}