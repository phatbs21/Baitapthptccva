#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long i, tong = 0;
    for (i = 1; i <= n; i++)
    {
        if (i % 15 != 0 && (i % 5) != 0 && (i % 3) != 0)
            tong += i;
    }
    cout << tong;
    return 0;
}