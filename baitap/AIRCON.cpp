#include <bits/stdc++.h>
using namespace std;
struct xuli
{
    int x, d;
};
bool cmp(xuli X, xuli Y)
{
    if ((X.x) > (Y.x))
        return (X.x) < (Y.x);
    return (X.x) < (Y.x);
}
int main()
{
    int n, dem = 1;
    cin >> n;
    xuli a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].d;
    }
    sort(a + 1, a + n + 1, cmp);
    int vitri = a[1].d;
    for (int i = 2; i <= n; i++)
    {
        if (vitri < a[i].x)
        {
            dem++;
            vitri = a[i].d;
        }
        else
        {
            vitri = min(a[i].d, vitri);
        }
    }
    cout << dem;
}