#include <bits/stdc++.h>
using namespace std;
int tongmang(int a[], int n)
{
    int tong = 0;
    for (int i = 1; i <= n; i++)
    {
        tong += a[i];
    }
    return tong;
}
int main()
{
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++)
    {
        int n, dem = 0;
        cin >> n;
        int a[n + 1];
        stack<int> q;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            if (a[i] == 0)
            {
                a[i]++;
                dem++;
            }
        }
        if (tongmang(a, n) == 0)
        {
            dem++;
        }
        cout << dem<<endl;
    }
}