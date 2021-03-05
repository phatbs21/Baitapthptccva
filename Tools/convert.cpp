#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    freopen("convert1.inp", "r", stdin);
    freopen("convert.out", "w", stdout);

    int t = 1026;
    while (t--)
    {
        getline(cin, s);
        for (int i = 0; i < s.length(); i++)
            if (s[i] == ' ')
                s.erase(s.begin() + i, s.end());
        cout << s << "\n";
    }
}