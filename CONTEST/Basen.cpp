#include <bits/stdc++.h>
using namespace std;
#define bignum string
bignum cong(bignum s1, bignum s2)
{
    while (s1.length() < s2.length())
        s1 = "0" + s1;
    while (s2.length() < s1.length())
        s2 = "0" + s2;
    bignum k = "";
    int c, nho = 0;
    for (int i = s1.length() - 1; i >= 0; i--)
    {
        c = (s1[i] - 48) + (s2[i] - 48) + nho;
        nho = c / 10;
        c = c % 10;
        k = char(c + 48) + k;
    }
    if (nho > 0)
        k = "1" + k;
    return k;
}
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
bignum nhan1(bignum s, int a)
{
    string k;
    int nho = 0, c;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        c = a * (s[i] - 48) + nho;
        nho = c / 10;
        c = c % 10;
        k = char(c + 48) + k;
    }
    while (nho > 0)
    {
        k = char(nho % 10 + 48) + k;
        nho /= 10;
    }
    return k;
}
bignum nhan(bignum s1, bignum s2)
{
    bignum k, t, d;
    for (int i = s2.length() - 1; i >= 0; i--)
    {
        t = nhan1(s1, s2[i] - 48) + d;
        k = cong(k, t);
        d = d + "0";
    }
    return k;
}

int val(char c)
{
    if (c >= '0' && c <= '9')
        return (int)c - '0';
    else
        return (int)c - 'A' + 10;
}
bignum toDeci(char *str, int base)
{
    int len = strlen(str);
    bignum power = "1";
    bignum num = "0";
    int i;
    for (i = len - 1; i >= 0; i--)
    {
        num = cong(nhan1(power, val(str[i])), num);
        power = nhan1(power, base);
    }

    return num;
}
string convertToString(char *a, int size)
{
    int i;
    string s = "";
    for (i = 0; i < size; i++)
    {
        s = s + a[i];
    }
    return s;
}

int main()
{
    string m;
    string s;
    cin >> s >> m;
    int base = 0, z = 0;
    char p[s.length()];
    for (int i = 0; i < sizeof(p); i++)
    {
        p[i] = s[i];
        base = max(base, s[i] - 48);
    }
    while (sosanh())
        return 0;
}
