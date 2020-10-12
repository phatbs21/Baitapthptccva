#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int dem = 0;
    // 1 5 10 20 100
    while (n / 100 != 0)
    {
        dem++;
        n -= 100;
    }
    while (n / 20 != 0)
    {
        dem++;
        n -= 20;
    }
    while (n / 10 != 0)
    {
        dem++;
        n -= 10;
    }
    while (n / 5 != 0)
    {
        dem++;
        n -= 5;
    }
    if (n > 0)
        dem += n;
    cout << dem;
}