#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s, p;
    int i, dem = 0;
    getline(cin,s);
    for (i = 0; i <= s.length()-1; i++)
        if (s.find(s[i]) == i) dem++;
    cout<<dem;
    return 0;
}
    