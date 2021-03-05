#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int m = n;
    if (n % 100 == 0)
        cout << abs(m - (n + 100));
    else
    {
        n = n / 100 + 1;
        cout << abs(m - n * 100);
    }
}