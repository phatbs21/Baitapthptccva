#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int tong = 0;
    for (int i = 1; i <= n; i++)
    {
        tong = tong + (n-1) / i;
    }
    cout << tong;
}