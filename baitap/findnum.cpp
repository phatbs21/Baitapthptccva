#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("findnum.INP", "r", stdin);
    //freopen("findnum.OUT", "w", stdout);
    string s="";
    cin >> s;
    if (s == "0" || s == "-0")
    {
        cout << 0;
        return 0;
    }
    int so, f1, Min;
    if (s[0] != '-')
    {
        stringstream ss;
        ss << s;
        ss >> f1;
        sort(s.begin(), s.end());
        Min = INT_MAX;
        do
        {
            stringstream s2;
            s2 << s;
            s2 >> so;
            if (so > f1 && so < Min && s[0] != '0')
            {
                Min = so;
            }
        } while (next_permutation(s.begin(), s.end()));
        if (Min != INT_MAX)
            cout << Min;
        else
            cout << 0;
    }
    else
    {
        s.erase(s.begin(), s.begin() + 1);
        stringstream s1;
        s1 << s;
        s1 >> f1;
        Min = INT_MIN;
        sort(s.begin(), s.end());
        do
        {
            stringstream s2;
            s2 << s;
            s2 >> so;
            if (so < f1 && so > Min && s[0] != '0')
            {
                Min = so;
            }
        } while (next_permutation(s.begin(), s.end()));
        if (Min != INT_MIN)
            cout << "-" << Min;
        else
            cout << 0;
    }
}