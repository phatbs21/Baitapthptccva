#include <bits/stdc++.h>
using namespace std;
#define ff first
#define ss second
int main()
{
    int n, dem = 0;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].ff >> a[i].ss;
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n - 1; i++)
    {
        int l = 0, r = n - 1;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (a[i].ss <= a[mid].ff)
                r = mid - 1;
            else
                l = mid + 1;
        }
        dem += l - i - 1;
    }
    cout << dem;
}
