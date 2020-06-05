#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("gienla.inp", "r", stdin);
    freopen("gienla.out", "w", stdout);
    string s;
    int n = 0;
    getline(cin, s);
    n = s.length();
    for (int i = 1; i <= n / 2 + 1; i++)
    {
        for (int j = 0; j <= n - i; j++)
        {
            if (s.find(s.substr(j, i), j + i) == string::npos)
            {
                if (s.find(s.substr(j, i)) == j)
                {
                    cout << s.substr(j, i);
                    return 0;
                }
            }
        }
    }
    cout << s;
    return 0;
}
