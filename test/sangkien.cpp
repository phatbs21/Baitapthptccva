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
string inra(int n)
{
    bignum s = "1";
    for (int i = 1; i <= n; i++)
    {
        s = nhan1(s, 2);
    }
    return s;
}
string kt(int n)
{
    int c = 0;
    int a = 0, dem = 0, b = 0;
    string s1, s2 = "";
    while (n > 0)
    {
        dem++;
        s1 = to_string(c);
        if (n % 2 == 1)
        {
            if (dem % 2)
                a += stoi(s1);
            else
                b += stoi(s1);
        }
        n = n / 2;
        c++;
    }
    cout<<"*"<<a<<""<<b<<"*";
    if (a > b)
        return cong(inra(a), nhan1(inra(b), 1));
    else
        return cong(inra(b), nhan1(inra(a), 1));
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int t;
    for (int i = 1; i <= n; i++)
    {
        cin >> t;
        cout << kt(t) << "\n";
    }
}
//6 0 1 2 3 4 5