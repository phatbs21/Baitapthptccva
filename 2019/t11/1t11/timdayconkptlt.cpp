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
    int Smax = -1e8, imax = 1;

    int s;
    for (int i = 1; i <= n - k + 1; i++)
    {
        s = 0;
        for (int j = i; j <= i + k - 1; j++)
        {
            s += a[j];
        }
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