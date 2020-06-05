#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int tong = 0;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int min = a[1];

    for (int i = 1; i <= n; i++)
    {
        if (a[i] > min)
        {
            tong = max(tong, a[i] - min);
        }
        else
        {
            min = a[i];
        }
    }
    cout << tong;//
}