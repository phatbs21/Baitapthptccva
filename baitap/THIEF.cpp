#include <bits\stdc++.h>
using namespace std;
struct xuli
{
    float x, d;
};
bool cmp(xuli X, xuli Y)
{
    if ((X.x) / (X.d) > (Y.x) / (Y.d))
        return (X.d) > (Y.d);
    return (X.x) > (Y.x);
}
int main()
{
    freopen("THIEF.INP", "r", stdin);
    freopen("THIEF.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int m;
    cin >> m;
    int n;
    cin >> n;
    xuli a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].x;
        cin >> a[i].d;
    }
    sort(a + 1, a + n + 1, cmp);
    int i = 0, j = 1;
    long long int tong = 0;
    while (i != m)
    {
        i++;
        tong += a[j].d;
        if (i == a[j].x)
        {
            i -= a[j].x;
            m -= a[j].x;
            j++;
        }
    }
    cout << tong;
}