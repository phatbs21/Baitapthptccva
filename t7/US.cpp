#include <bits/stdc++.h>

using namespace std;

const int N = 1000000;
int e[N + 1], s[N + 1], T[N + 1];

void sanNguyenTo()
{
    for (int i = 1; i <= N; ++i)
    {
        e[i] = i;
    }
    for (int i = 2; i <= N / i; ++i)
    {
        if (e[i] == i)
        {
            for (int j = 2; j <= N / i; ++j)
            {
                e[i * j] = i;
            }
        }
    }
    return;
}

void tinhMang()
{
    int p, k, y, kq;
    s[1] = 1;
    for (int x = 2; x <= N; ++x)
    {
        p = e[x], y = x, k = 0;
        while (y % p == 0)
        {
            ++k, y /= p;
        }
        s[x] = (k + 1) * s[y];
    }
    T[1] = 1;
    for (int x = 2; x <= N; ++x)
    {
        p = e[x];
        y = x;
        kq = 1;
        while (y % p == 0)
        {
            kq = 1 + p * kq;
            y /= p;
        }
        T[x] = kq * T[y];
    }
    return;
}
int main()
{

    freopen("US.inp", "r", stdin);
    int t;
    cin >> t;
    sanNguyenTo();
    tinhMang();
    for (int test = 1; test <= t; test++)
    {
        int a, b;
        cin >> a >> b;
        int tong = 0, soluong = 0;
        for (int i = a; i <= b; i++)
        {
            tong += T[i];
            soluong += s[i];
        }
        cout << soluong << " " << tong << endl;
    }
}