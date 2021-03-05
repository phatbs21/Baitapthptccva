#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

int main()
{
    //freopen("gcdoper.inp", "r", stdin);
    //freopen("gcdoper.out", "w", stdout);

    int n;
    cin >> n;
    int z;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    /* 5 2 2 3 4 6
    while (cin >> z)
    {
        a.push_back(z);
    }*/
    int dem = 0;
    for (int j = 0; j < a.size(); j++)
        for (int i = 0; i < a.size() - 1; i++)
        {
            int c = i + 1;
            if (a[i] == a[c])
                continue;
            int kt = 0;
            if (isPrime(a[i]) && isPrime(a[c]))
                kt = 0;
            else if (isPrime(a[i]))
                kt = 1;
            else if (isPrime(a[c]))
                kt = 2;
            if (kt == 0)
            {
                if (a[i] % 2 == 1 && a[c] % 2 == 1)
                    kt = 0;
                if (a[i] % 2 == 1)
                    kt = 2;
                else if (a[c] % 2 == 1)
                    kt = 1;
            }
            if (kt == 0)
            {
                if (a[i] < a[c])
                    kt = 1;
                else if (a[i] > a[c])
                    kt = 2;
                else
                    kt = 3;
            }
            if (a[c] == 1 && a[i] != 1)
            {
                dem++;
                a[i] = 1;
                continue;
            }
            if (a[c] != 1 && a[i] == 1)
            {
                dem++;
                a[c] = 1;
                continue;
            }
            if (kt == 1)
                a[i] = __gcd(a[i], a[c]);
            else if (kt == 2)
                a[c] = __gcd(a[i], a[c]);
            else if (kt == 3)
            {
                a[c] = __gcd(a[i], a[c]);
            }

            dem++;
        }
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] != 1)
        {
            cout << -1;
            return 0;
        }
    }
    cout << dem;
}