#include <bits/stdc++.h>
using namespace std;
string nhan1(string s, int a)
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

int main()
{
    int n;
    cin >> n;
    string tong = "1";
    for (int i = 1; i <= n; i++)
    {
        tong = nhan1(tong, i);
    }
    cout << tong;
}