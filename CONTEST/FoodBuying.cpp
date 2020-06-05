#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Og")
#pragma GCC push_options
#pragma GCC pop_options

int rasoat(long long int a)
{
    long long int s = 1;
    if (a==0)
    return 0;
    if (a <= 9)
    {
        return s;
    }
    while (a > 1)
    {
        s = s + (a / 10) * 10;
        a = a / 10 + a % 10;
        if (a < 10)
        {
            s = s + a;
            break;
        }
        if ((a - 10 < 10) && (a - 10 > 0))
        {
            s = s + a + 1;
            break;
        }
    }
    return s - 1;
}

int main()
{
    long long int i, n;
    cin >> n;
    long long int a[n + 10];
    for (i = 1; i <= n; i++)
        cin >> a[i];
    for (i = 1; i <= n; i++)
        cout << rasoat(a[i]) << endl;
}