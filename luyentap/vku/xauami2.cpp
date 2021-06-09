#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    bool flag = false;
    string s1;
    while (s.length() > 1)
    {
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == s[i + 1] && i < s.length() - 1)
            {
                s.erase(i, 2);
            }
        }
    }
    if (s.length() == 1)
    {
        cout << 0;
    }
    else
        cout << 1;
}