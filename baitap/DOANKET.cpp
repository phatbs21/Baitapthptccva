#include <bits/stdc++.h>
using namespace std;
long long int kt(int a[], int n)
{
    long long int tong = 0;
    for (int i = 0; i < 32; i++)
    {
        int b = 0, c = 0;
        long long int id = 0;
        for (int j = 0; j < n; j++)
        {
            if (a[j] % 2 == 0)
                b++;
            else
                c++;
            a[j] /= 2;
        }
        id = c * b * (1 << i);
        tong += id;
    }
    return tong;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("DOANKET.INP", "r", stdin);
    freopen("DOANKET.OUT", "w", stdout);
    long long int tong = 0;
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    tong = kt(a, n);
    cout << tong;
    return 0;
}