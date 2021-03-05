#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int a[100], n, dem;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
        if (a[i] >= dem)
            ++dem;
    cout << dem;
}
