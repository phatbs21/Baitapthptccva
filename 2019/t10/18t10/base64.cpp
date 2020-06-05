#include <bits\stdc++.h>

using namespace std;

const string cs = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
int mu(int a,int b)
{
    int d=1;
    for (int i=1;i<=b;i++)
    d=d*a;
    return d;
}

string endcodebase64(string s)

{
    string p;
    int i = 0, j = -6;
    for (int k = 0; k < s.length(); k++)
    {
        char c = s[k];
        i = (i << 8) + c;
        j += 8;
        while (j >= 0)
        {
            p.push_back(cs[(i >> j) % 64]); // i>>j = i/2^j
            j -= 6;                         //&63 = a mod 64
        }
    }
    if (j > -6)
        p.push_back(cs[((i << 8) >> (j + 8)) % 64]); //i<<8=i*2^8
    while (p.size() % 4)
        p.push_back('=');
    return p;
}
string decodebase64(string s)
{
    string p;
    vector<int> T(256, -1);
    for (int i = 0; i < 64; i++)
        T[cs[i]] = i;
    int i = 0, j = -8;
    for (int k = 0; k < s.length(); k++)
    {
        char c = s[k];
        if (T[c] == -1)
            break;
        i = (i << 6) + T[c];
        j += 6;
        if (j >= 0)
        {
            p.push_back(char((i >> j) % 256));
            j -= 8;
        }
    }
    return p;
}
int main()
{
    string s = "lenguyentanphat";
    //cin >> s;
    cout << endcodebase64(s) << endl;
    cout << decodebase64(endcodebase64(s));
}