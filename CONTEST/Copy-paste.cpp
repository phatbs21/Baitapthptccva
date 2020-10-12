#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    vector<int> a;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        a.resize(n);
        for (auto &i : a)
            cin >> i;
        sort(a.begin(), a.end());
        int j = 0;
        for (int i = 1; i < n; i++)
        {
            while (a[i] + a[0] <= k)
            {
                a[i] += a[0];
                j++;
            }
        }
        cout << j << "\n";
    }
}