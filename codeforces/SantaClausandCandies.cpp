#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int m = 1;
    while (m * (m + 1) <= 2 * n)
        m++;

    m--;

    cout << m;
    for (int i = 1; i < m; i++)
    {
        cout << i;
        n -= i;
    }
    cout << n;
}