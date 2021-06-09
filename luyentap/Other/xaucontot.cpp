#include <bits/stdc++.h>
using namespace std;
bool doixung(string s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != s[s.length() - i - 1])
            return false;
    }
    return true;
}
string daidien(string s)
{
    string s1;
    for (int i = 0; i < s.length()-1 ; i++)
    {
        if (s[i] != s[i +1])
            s1 += s[i];
    }
    return s1;
}
int main()
{
    string s;
    cin >> s;
    cout<<daidien(s);
}