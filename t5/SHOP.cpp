#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n + 1];
    int tong = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] > tong)
        {
            cout << tong;
            return 0;
        }
        tong += a[i];
    }
    cout << tong;
}
