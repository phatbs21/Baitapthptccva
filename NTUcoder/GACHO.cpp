#include <bits/stdc++.h>
using namespace std;
int main()
{
    int z, n, m;
    cin >> n >> m;
    for (z = 0; z <= n; z++)
        if ((z * 2 + (n - z) * 4) == m)
        {
            cout << z << " " << n - z;
            return 0;
        }
    cout << -1;
    return 0;
}