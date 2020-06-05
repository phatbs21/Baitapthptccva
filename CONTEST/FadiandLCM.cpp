#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Og")
#pragma GCC push_options
#pragma GCC pop_options

bool snt(int a)
{
    if (a < 2)
    {
        return false;
    }
    else if (a > 2)
    {
        if (a % 2 == 0)
        {
            return false;
        }
        for (int i = 3; i < sqrt((float)a); i += 2)
        {
            if (a % i == 0)
            {
                return false;
            }
        }
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long int n;
    cin >> n;
    const int q=n;
    int a, b;
    while (n > 1)
    {
        if (n % 2 == 0 && n / 2 != 1)
        {
            n = n / 2;
            a = n;
        }
        else
        {
            if (snt(n) != true)
            {
                b = n;
                cout<<1;
                break;
            }
            else
            {
                for (int i = 3; i <= q / 2; i += 2)
                {
                    if (n % i == 0)
                    {
                        b = n;
                        n = n / i;
                        break;
                    }
                }
            }
        }
    }
    cout<<a<<" "<<b;
}
