#include <bits/stdc++.h>
using namespace std;
#define NAME "eksplozija"
#define tocdo cout << "Time " << clock() / (double)1000 << " sec"
ifstream fi(NAME ".inp");
ofstream fo(NAME ".out");

int main()
{
    string s, s2;
    fi >> s;
    s2 = s;
    string s1;
    fi >> s1;
    int found;
    found = s.find(s1);
    while (found != std::string::npos)
    {
        s.erase(found, s1.length());
        found = s.find(s1);
    }
    if (s == "")
        fo << "miss you baby";
    else
        fo << s;
}