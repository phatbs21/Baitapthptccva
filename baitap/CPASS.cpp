#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("CPASS.inp", "r", stdin);
    string s, s1, s2;
    getline(cin, s);
    s1 += s[0];
    int n1 = s.length();
    for (int j = 0; j < n1 / 3; j++)
    {
        if (j != 0)
            s1 += s[j];
        int n = s1.length();
        s2 = s.substr(n1 - n, n);
        if (s1 == s2)
        {
            if (s.find(s1, n) != string::npos)
            {
                if (s1 != "")
                    cout << s1;
                else
                    cout << "Just a joke";
                return 0;
            }
        }
    }
    cout << "Just a joke";
}