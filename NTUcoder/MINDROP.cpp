#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, t=1;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    int ans = 0;
    for (int i = 0; i < n - 1; i++)
        if (a[i] == a[i + 1])
        {
            t++;
        }
        else
        {
            ans = max(ans, t);
            t = 1;
        }
    cout << n - ans;
}