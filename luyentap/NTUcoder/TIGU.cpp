#include <bits/stdc++.h>
using namespace std;

int main()
{
    float n, m, dem;
    cin >> n >> m;
    while (n < m)
    {
        n = n + round(n * 1 / 10);
        dem++;
    }
    cout << dem;
}
