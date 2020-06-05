#include <bits/stdc++.h>
using namespace std;
int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    int dem = 1;

    while (a < c)
    {
        dem++;
        c -= (a - b);
    }

    cout << dem;
    return 0;
}
