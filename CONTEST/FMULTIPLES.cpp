#include <bits/stdc++.h>
#define lli long long int
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    lli dem = 0, b;
    vector<lli> a;
    cin >> s;
    a.resize(s.length());
    for (int i = 0; i < s.length(); ++i)
    {
        a[i] = s[i] - 48;
        if (a[i] % 4 == 0)
            dem++;
    }
    for (int i = 0; i < s.length() - 1; ++i)
    {
        b = a[i];
        for (int j = i + 1; j < s.length(); ++j)
        {
            b = b * 10 + a[j];
            if (b % 4 == 0)
                dem++;
        }
    }
    cout << dem;
}
