#include <bits\stdc++.h>
#include <chrono>
using namespace std;
const string cs = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

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
            p.push_back(cs[(i >> j) & 63]); // i>>j = i/2^j
            j -= 6;                         //&63 = a mod 64
        }
    }
    if (j > -6)
        p.push_back(cs[((i << 8) >> (j + 8)) & 63]); //i<<8=i*2^8
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
            p.push_back(char((i >> j) & 255));
            j -= 8;
        }
    }
    return p;
}