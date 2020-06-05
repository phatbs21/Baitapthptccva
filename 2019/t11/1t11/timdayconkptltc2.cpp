#include <bits\stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n + 1];
    int k;
    cin >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int s=0;
    for (int i = 1; i <= k; i++)
        s += a[i];
    int Smax = s, imax = 1;
    for (int i = 2; i <= n - k + 1; i++)
    {
        s = s - a[i - 1] + a[i + k - 1];
        if (s > Smax)
        {
            Smax = s;
            imax = i;
        }
    }

    cout << Smax << endl;
    for (int i = imax; i <= imax + 2; i++)
        cout << a[i] << endl;
}