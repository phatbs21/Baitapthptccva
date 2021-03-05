#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    vector<bool> d(n, false);
    for (auto &i : a)
        cin >> i;
    int q = n, tong = 0;
    sort(a.begin(), a.end());
    while (q--)
    {
        if (d[q] != true)
        {
            int upper = q, temp = a[q] - k;
            while (0 == 0)
            {
                upper = lower_bound(a.begin(), a.begin() + upper - 1, temp) - a.begin();
                if (upper == 0)
                    break;
                temp = a[upper] - k;
                d[upper] = true;
            }
            tong += a[q];
        }
    }
    cout << tong;
}
