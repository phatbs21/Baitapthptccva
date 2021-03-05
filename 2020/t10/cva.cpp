#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("cva.inp", "r", stdin);
    freopen("cva.out", "w", stdout);
    string s, s1;
    getline(cin, s);
    //s = "CHAO CAC BAN CHUYEN VAN CVA";
    vector<int> p(s.length() + 5, 0);
    for (int i = s.length() - 1; i >= 0; i--)
    {
        p[i] = p[i + 1] + (s[i] == 'A');
    }
    int c = 0;
    long long int dem = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'V')
        {
            dem += c * p[i];
        }
        if (s[i] == 'C')
        {
            c++;
        }
    }
    cout << dem;
 /*
    vector<int> a;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'C')
            a.push_back(1);
        if (s[i] == 'V')
            a.push_back(2);
        if (s[i] == 'A')
            a.push_back(3);
    }
    bool flagC = false, flagV = false, flagA = false;
    int i = 0;
    while (i < n)
    {
        if (a[i] == 1)
            flagC = true;
        if (a[i] == 2 && flagC == false)
        {
            a.erase(a.begin() + i);
            n--;
        }
        if (a[i] == 2)
            flagV = true;
        if (a[i] == 3 && flagV == false)
        {
            a.erase(a.begin() + i);
            n--;
        }
    }
    */}