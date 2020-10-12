#include <bits/stdc++.h>
using namespace std;
bool nto(int n)
{
    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
int main()
{
    int t, m, n;
    cin >> t;
    for (int test = 1; test <= t; test++)
    {
        cin >> m >> n;
        if (m <= 2)
        {
            cout << 2 << "\n";
            m = 3;
        }
        else if (m % 2 == 0)
        {
            m++;
        }
        while (m <= n)
        {
            if (nto(m)==true)
            {
                cout << m << "\n";
            }
            m += 2;
        }
        cout << "\n";
    }
}
