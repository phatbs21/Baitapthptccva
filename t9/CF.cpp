#include <bits/stdc++.h>
#define NAME "CF."
#define ff first
#define ss second
using namespace std;
ifstream fi(NAME "inp");
ofstream fo(NAME "out");
stringstream ss;
int main()
{
    string s;
    fi >> s;
    int ls = s.size();
    char c = s[ls - 1];
    if (c > 96)
        c -= 32;
    float r;
    ss << s;
    ss >> r;
    if (c == 'C')
    {
        r = r * 1.8 + 32;
        c = 'F';
    }
    else
    {
        r=(r-32)/1.8;
        c='C';
    }
    fo<<fixed<<setprecision(2)<<r<<c;
}
