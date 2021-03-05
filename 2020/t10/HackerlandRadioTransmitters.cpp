#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    sort(a.begin(), a.end());
    int soluong = 0;
    int l = -1, r = -1, ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] <= r)
            continue;
        if (l == -1)
            l = a[i];
        else if (a[i] - l > k)
        {
            ans++;
            if (a[i] - a[i - 1] <= k)
                l = -1;
            else
                l = a[i];
            r = a[i - 1] + k;
        }
    }
    cout << ans + (l != -1);
}