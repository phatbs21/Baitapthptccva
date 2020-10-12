#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (auto &i : a)
        cin >> i;
    int tot = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i] + a[i - 1] < k)
        {
            tot += k - a[i] - a[i - 1];
            a[i] = k - a[i - 1];
        }
    }
    cout << tot << "\n";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << "\n";
}