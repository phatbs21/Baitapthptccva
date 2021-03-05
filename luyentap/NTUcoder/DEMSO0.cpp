#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, dem = 0;
    cin >> n;
    while (n >= 5)
    {
        n = n / 5;
        dem = dem + n;
    }
    cout << dem;
    if (n == 5)
        cout << 1;
    return 0;
}
