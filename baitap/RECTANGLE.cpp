#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("RECTANGLE.INP", "r", stdin);
    freopen("RECTANGLE.OUT", "w", stdout);
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    int b = 0, c = 0;
    for (int i = n; i >= 2; i--)
    {
        if (a[i] == a[i - 1])
        {
            if (b == 0)
            {
                b = a[i];
            }
            else
            {
                c = a[i];
                break;
            }
        }
    }
    cout << b * c;
}