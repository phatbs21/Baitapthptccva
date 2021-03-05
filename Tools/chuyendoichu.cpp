#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("in.inp", "r", stdin);
    freopen("out.out", "w", stdout);
    string s;
    while (getline(cin, s))
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 9 || s[i] == 32 || (s[i] >= 65 && s[i] <= 90) || (s[i] >= 97 && s[i] <= 122) || (s[i] > 255))
                cout << s[i];
        }
        cout << endl;
    }
}