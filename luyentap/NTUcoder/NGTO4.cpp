#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long x, a, du, t;
    cin >> t;
    for (long i = 0; i < t; i++)
    {
        cin >> x;
        a = x / 7;
        du = x % 7;
        if (a == 0 && (du == 1 || du == 0))
            du = -1;
        else if (du == 2 || du == 3 || du == 5)
            du = 1;
        else if (du == 4 || du == 6)
            du = 2;
        else if (du == 0)
            du = 0;
        cout << a + du << endl;
    }
    return 0;
}