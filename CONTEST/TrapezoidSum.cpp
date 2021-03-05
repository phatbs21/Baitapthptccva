#include <bits/stdc++.h>
using namespace std;

 int main()
{
    long long int n;
    cin >> n;
    long long int tong = 0;
    for (long long int i = 0; i < n; i++)
    {
        long long int a, b;
        cin >> a >> b;
        tong += (a + b) * (b - a + 1) / 2;
    }
    cout << tong;
}