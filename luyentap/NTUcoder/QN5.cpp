#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int x = sqrt(n);
    if (x * x < n)
        x++;
    if (x * (x - 1) >= n)
    {
        cout << x - 1 << " " << x;
    }
    else
    {
        cout << x << " " << x;
    }
}
