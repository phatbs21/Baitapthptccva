#include <bits\stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int d[n + 1];
    for (int i = 0; i <= n; i++)
    {
        d[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        d[a[i]] = 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (d[i] == 0)
        {
            cout << i;
            return 0;
        }
    }
    return 0;
}