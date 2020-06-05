#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("test.inp", "r", stdin);
    int k = 0, n, m;
    cin >> n >> m;
    int a[n + 1], b[m + 1];
    int c[m + n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int j = 1; j <= m; j++)
    {
        cin >> b[j];
    }
    int i = 1, j = 1;
    while ((i <= n) && (j <= m))
    {

        if (a[i] < b[j])
        {
            k++;
            c[k] = a[i];
            i++;
        }
        else
        {
            k++;
            c[k] = b[j];
            j++;
        }
    }
    while (i <= n)
    {
        k++;
        c[k] = a[i];
        i++;
    }
    while (j <= m)
    {
        k++;
        c[k] = b[j];
        j++;
    }
    for (k = 1; k <= (m + n); k++)
    {
        cout << c[k] << "  ";
    }
}
