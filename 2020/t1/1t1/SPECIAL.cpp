#include <bits/stdc++.h>
using namespace std;
#define bignum string
int z;
int sosanh(bignum s1, bignum s2)
{
    if (s1.length() > s2.length())
        return 1;
    if (s2.length() > s1.length())
        return -1;
    if (s1 == s2)
        return 0;
    if (s1 > s2)
        return 1;
    return -1;
}
string left(bignum a, int b)
{
    return a.substr(b);
}
string rev(bignum a)
{
    reverse(a.begin(), a.end());
    return a;
}
string right(bignum a, int b)
{

    a = rev(a);
    string c = left(a, b);
    c=rev(c);
    return c;
}

int main()
{
            freopen("SPECIAL.inp", "r", stdin);
        freopen("SPECIAL.out", "w", stdout);
    bignum n;
    cin >> n;
    z = n.length();
    if (n == "0")
    {
        cout << "Yes";
        return 0;
    }
    long long int x;
    x=n.length();
    if (x/2+1<x)
    {
        x=x/2+1;
    }
    if (sosanh(left(n,x), rev(right(n,x))) == 0)
        cout << "Yes";
    else
        cout << "No";
}