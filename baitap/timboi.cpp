#include <bits/stdc++.h>
using namespace std;
int main()
{

    long long int x, minn = 1e18, n, temp;
    cin >> n >> x;
    for (int i = 1; i <= n; ++i)
    {
        cin >> temp;
        if (x % temp == 0)
        {
            cout << x;
            return 0;
        }
        if (temp < x)
            temp = (x / temp + 1) * temp;
        if (temp < minn)
            minn = temp;
    }
    cout << minn;
}
