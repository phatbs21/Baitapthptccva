#include <bits/stdc++.h>
using namespace std;
bool Check(long double x)
{
    long double sr = sqrt(x);
    return ((sr - floor(sr)) == 0);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("SQRNUM.INP", "r", stdin);
    freopen("SQRNUM.OUT", "w", stdin);
    long double x, tong = 1;
    long n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        tong *= x;
        if (Check(tong))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}