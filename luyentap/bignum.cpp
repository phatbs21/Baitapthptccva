#include <bits/stdc++.h>
using namespace std;
#define bignum string
bool sosanh(bignum s1, bignum s2)
{
    if (s1.length() > s2.length())
        return 1;
    if (s1.length() < s2.length())
        return -1;
    if (s1 == s2)
        return 0;
    if (s1 > s2)
        return 1;
    return -1;
}
bool cong(bignum s1,bignum s2)
{
    while(s1.length()<s2.length())
    s1="0"+s1;
    while(s2.length()<s1.length())
    
}