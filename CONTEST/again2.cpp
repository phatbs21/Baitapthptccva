#include <bits/stdc++.h>
using namespace std;
string s;
long long int n;
long long int x[1005], a[1005], b[1005];
bool check()
{
    for (int i = 0; i < n; i++)
    {
        if ((s[i] == '<' && a[i] >= a[i + 1]) || (s[i] == '>' && a[i] <= a[i + 1]) || a[i] < 0 || a[i + 1] < 0 )
            return false;
    }
    return true;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("atest.inp", "r", stdin);
#endif
    cin >> n >> s;
    for (int i = 0; i <= n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    memset(x, 10000000, sizeof(x));
    x[0] = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '>')
        {
            x[i + 1] = x[i] - 1;
        }
        else
        {
            x[i + 1] = x[i] + 1;
        }
    }
    int minn = *min_element(x, x + n + 1);
    if (minn < 1)
        for (int i = 0; i <= n; i++)
        {
            x[i] += (abs(minn));
        }
    // phia tren on (x[i])
    while (check() == true)
    {
        for (int i = 0; i <= n; i++)
            a[i] = b[i];
        dem++;
        for (int i = 0; i <= n; i++)
        {
            a[i] -= x[i] * dem;
        }
    }
    cout << dem << "\n";
    for (int i = 1; i < dem; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            cout << x[j] << " ";
        }
        cout << "\n";
    }
    for (int i = 0; i <= n; i++)
    {
        cout << b[i] - (dem - 1) * x[i] << " ";
    }
}