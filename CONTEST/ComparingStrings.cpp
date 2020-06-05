#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Og")
#pragma GCC push_options
#pragma GCC pop_options
#define bignum string
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
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int a, b;
    cin >> a >> b;
    bignum a1, a2, aa, bb;
    aa = to_string(a);
    bb = to_string(b);
    for (int i = 1; i <= b; i++)
    {
        a1 += aa;
    }
    for (int i = 1; i <= a; i++)
    {
        a2 += bb;
    }
    if (sosanh(a1, a2) >= 0)
    {
        cout << a1;
    }
    else
    {
        cout << a2;
    }
}