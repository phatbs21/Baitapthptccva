#include <bits/stdc++.h>
using namespace std;
int main()
{
    int64_t t;
    cin >> t;
    while (t--)
    {
        int64_t q, n;
        cin >> n >> q;
        vector<int64_t> a(n);
        for (auto &i : a)
            cin >> i;
        int64_t dem = 0, tong = 0;
        for (int64_t i = 0; i < n - 1; ++i)
        {
            if (dem % 2 == 0)
            {
                if (a[i] > a[i + 1])
                {
                    tong += a[i];
                    dem++;
                }
            }
            else
            {
                if (a[i] < a[i + 1])
                {
                    tong -= a[i];
                    dem++;
                }
            }
        }
        if (dem % 2 == 0)
        {
            tong += a[n - 1];
        }
        cout << tong << "\n";
    }
}