#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n;
    m = n;
    while (m >= 10)
    {
        m = m - 7;
        n = n + 3;
    }
    cout << n;
}