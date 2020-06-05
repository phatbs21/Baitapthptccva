#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Og")
#pragma GCC push_options
#pragma GCC pop_options
int interpolationSearch(int arr[], int n, int x)
{
    int lo = 0, hi = (n - 1);
    while (lo <= hi && x >= arr[lo] && x <= arr[hi])
    {
        if (lo == hi)
        {
            if (arr[lo] == x)
                return lo;
            return -1;
        }
        int pos = lo + (((double)(hi - lo) / (arr[hi] - arr[lo])) * (x - arr[lo]));
        if (arr[pos] == x)
            return pos;
        if (arr[pos] < x)
            lo = pos + 1;
        else
            hi = pos - 1;
    }
    return -1;
}
int main()
{
    freopen("ConneRandthe.inp", "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int z = 1; z <= t; z++)
    {
        int n, s, k;
        cin >> n >> s >> k;
        int a[k + 1];
        for (int i = 0; i < k; i++)
        {
            cin >> a[i];
        }
        sort(a, a + k);
        if (binary_search(a, a + k, s) == false)
        {
            cout << 0 << endl;
            continue;
        }
        for (int i = 0; i <= s; i++)
        {
            if (binary_search(a, a + k, s - i) == false || binary_search(a, a + k, s + i) == false)
            {
                cout << i;
                break;
            }
        }
    }
}