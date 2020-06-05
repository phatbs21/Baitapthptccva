#include <bits/stdc++.h>
using namespace std;
string x, y, Min = "99999999", Max = "0";
int a, m, n;
void thu(int i, int j, string s)
{
    if (s.length() == a)
    {
        Min = min(Min, s);
        Max = max(Max, s);
    }
    if (i < n)
    {
        thu(i + 1, j, s + x[i]);
    }
    if (j < m)
    {
        thu(i, j + 1, s + y[j]);
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> x >> y;
    n = x.length();
    m = y.length();
    a = n + m;
    thu(0, 0, "");
    cout << Min << endl
         << Max;
    return 0;
}
