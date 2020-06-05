#include <bits/stdc++.h>
using namespace std;

int main()
{
    //freopen("bb.INP", "r", stdin);
    string s;
    getline(cin,s);
    s.erase(0, s.find(":"));
    string s1 = s.substr(0, s.find(","));
    cout<<s1;
}