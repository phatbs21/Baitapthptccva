#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int a, n, m=1;
    cin >> a >> n;
    for (int i = 1; i <= n; i++)
    {
        m = m * a;
        m = m % 10;
    }
    cout << m;
}