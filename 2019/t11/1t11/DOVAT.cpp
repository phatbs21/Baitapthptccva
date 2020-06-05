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
    return (X.x) < (Y.x);
}

int main()
{
    int n;
    cin >> n;
    xuli a[n + 1];
    int k;
    cin >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].x;
        cin >> a[i].d;
    }
    int s[n + 1];
    int t = 0, dem = 0;
    float z = 0;
    sort(a + 1, a + n + 1, cmp);
    while (t < k)
    {
        t += a[dem].x;
        dem--;
    }
    cout << t;
}