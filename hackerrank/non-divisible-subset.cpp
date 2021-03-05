#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(k, 0);
    for (auto &i : a)
        cin >> i;
    for (int i = 0; i < n; i++)
        b[a[i] % k]++;
    if (k % 2 == 0)
        b[k / 2] = min(b[k / 2], 1);
    int res = min(b[0], 1);
    for (int i = 1; i <= k / 2; i++)
        res += max(b[i], b[k - i]);
    cout << res;
}