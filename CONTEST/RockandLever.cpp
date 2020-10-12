#include <bits/stdc++.h>
using namespace std;
int main()
{
    int64_t t;
    int64_t n;
    vector<int64_t> a;
    cin >> t;
    while (t--)
    {
        cin >> n;
        a.resize(n);
        for (auto &i : a)
        {
            cin >> i;
        }
        vector<int64_t> cnt(100, 0);
        int64_t tong = 0;
        for (int64_t i = 0; i < n; i++)
        {
            int64_t st = 1, po = 0;
            while (st * 2 <= a[i])
            {
                st <<= 1;
                po++;
            }
            tong += cnt[po];
            cnt[po]++;
        }
        cout << tong << "\n";
    }
}