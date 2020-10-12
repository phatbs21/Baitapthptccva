#include <bits/stdc++.h>
using namespace std;
int main()
{
    char t;
    cin >> t;
    string s;
    cin >> s;
    if (((int)t) == 'Y')
    {
        transform(s.begin(), s.end(), s.begin(), ::toupper);
    }
    else
    {
        for (auto &c : s)
        {
            c = tolower(c);
        }
    }
    cout<<s;
}