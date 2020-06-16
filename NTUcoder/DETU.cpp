#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    long dem, n;
    cin >> s;
    n = s.length();
    dem = 0;
    for (int i = 1; i < n; i++)
    {
        if (s[i] == '.' && s[i - 1] != '.')
            dem++;
    }
    if (s[n - 1] != '.')
        dem++;
    cout << dem;
}