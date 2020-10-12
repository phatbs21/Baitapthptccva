#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, x;
        cin >> n >> x;
        int dem = 1;
        if (n <= 2)
            dem = 1;
        else
        {
            n-=2;
            if (n % x > 0)
                dem += 1 + n / x;
            else
                dem += n / x;
        }

        cout << dem << endl;
    }
}