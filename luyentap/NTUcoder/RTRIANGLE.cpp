#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    double n, m;
    cin >> n;
    m = int(sqrt(2 * n));
    if (m * (m + 1) == 2 * n)
        cout << "YES";
    else
        cout << "NO";
}
