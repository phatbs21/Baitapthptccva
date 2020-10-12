#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, r, dem = 0;
    cin >> n >> r;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    // tim kiem nhi phan
    for (int i = 0; i < n - 1; i++)
    {
        int lf = i + 1, ri = n - 1;
        long long int tong = 0;
        while (lf <= ri)
        {
            int mi = (lf + ri) >> 1;
            if (a[mi] - a[i] > r)
            {
                tong = n - mi;
                ri = mi - 1;
            }
            else
                lf = mi + 1;
        }
        dem += tong;
    }
    cout << dem;
}
