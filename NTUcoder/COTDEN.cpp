#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n, m;
    cin >> n >> m;
    if (n % 2 == 1)
    {
        n++;
    }
    if (m % 2 == 1)
    {
        m++;
    }
    cout << n * m / 4;
}
