#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<vector<int>> f(n + 1, vector<int>(2, 0));
        for (auto &i : a)
            cin >> i;

        for (int i = 1; i < n; i++)
        {
            f[i][0] = max(f[i - 1][0], f[i - 1][1] + (a[i - 1] - 1));
            f[i][1] = max(f[i - 1][0] + a[i] - 1, f[i - 1][1] + abs(a[i] - a[i - 1]));
        }
        cout << max(f[n - 1][0], f[n - 1][1]) << "\n";
    }
}