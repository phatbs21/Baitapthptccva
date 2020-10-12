#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    string a;
    for (char c : s)
        a += '.', a += c;
    a += '.';
    n++;
    vector<int> f(n);
    int r = 0, c = 0;
    for (int i = 0; i < n; i++)
    {
        if (i < r)
        {
            f[i] = min(r - i, f[c - (i - c)]);
        }
        else    m
        {
            f[i] = 0;
        }
        while (a[i - f[i] - 1] == a[i + f[i] + 1])
        {
            f[i]++;
        }
        if (i + f[i] > r)
        {
            r = i + f[i];
            c = i;
        }
    }

    cout << *max_element(f.begin(), f.end());
}