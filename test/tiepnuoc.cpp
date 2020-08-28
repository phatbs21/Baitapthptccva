#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    for (int test = 1; test <= t; test++)
    {
        int dem = 0;
        int n, k;
        cin >> n >> k;
        if (k == 0)
        {
            cout << 0 << endl;
            continue;
        }
        int a[n + 1], tong = 0, vitri;
        sort(a + 1, a + n + 1);
        for (int i = 1; i <= n; i++)
        {
            if (a[i] > k)
                vitri = i;
        }
        for (int i = 1; i <= vitri; i++)
        {
            tong = 0;
            for (int j = 1; j <= vitri; j++)
            {
                tong += a[j];
            }
            if (tong == k)
            {
                dem++;
            }
        }
        if (dem == 0)
            cout << -1 << endl;
        else
            cout << dem << endl;
    }
}