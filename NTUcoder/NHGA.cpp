#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, a[100000], tong, b;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n, greater<int>());
    tong = a[0] - a[1];
    for (int i = 2; i < n; i++)
    {
        b = a[i - 1] - a[i];
        if (b != 0)
            tong = min(tong, b);
    }
    cout << tong;
    return 0;
}