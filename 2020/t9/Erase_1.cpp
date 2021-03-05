#include <bits/stdc++.h>
using namespace std;
#define NAME "Erase_1"

ifstream fi(NAME ".inp");
ofstream fo(NAME ".out");
int main()
{
    int t;
    fi >> t;
    while (t--)
    {
        string s;
        fi >> s;
        string s1 = s, s2 = s;
        bool q = false, w = false, dau = false;
        if (s[0] == '-')
        {
            dau = true;
            s.erase(s.begin());
        }
        for (int i = 1; i < s.length(); i++)
        {
            if ((s[i] - 48) < (s[i - 1] - 48))
            {
                s2.erase(s2.begin() + i - 1);
                w = true;
                break;
            }
        }
        if (w == false)
        {
            s2.erase(s.length() - 1, s.length() - 1);
        }
        for (int i = 1; i < s.length(); i++)
        {
            if ((s[i] - 48) > (s[i - 1] - 48))
            {
                s1.erase(s1.begin() + i - 1);
                q = true;
                break;
            }
        }
        if (q == false)
        {
            s1.erase(0, 0);
        }
        fo << s2 << " " << s1 << "\n";
    }
}