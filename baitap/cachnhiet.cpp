#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(2 * n - 1, 0), b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }
    sort(b.begin(), b.end());

    int i = 0, j = n - 1, k = 0;
    vector<int> c;
    while (i <= j)
    {
        a[i] = b[i];
        a[i + 1] = b[j];
        c.push_back(a[i]);
        c.push_back(a[i + 1]);
        i += 1;
        j--;
    }
    if (n % 2 != 0)
        c.pop_back();
    for (int i = 0; i < n; i++)
    {
        a[i] = c[i];
    }
    for (int i = 1; i < n; i += 2)
    {
        if (a[i - 1] > a[i])
            swap(a[i - 1], a[i]);
    }

    for (int i = 0; i < n - 1; i++)
    {
        a[i + n] = max(0, a[i + 1] - a[i]);
    }
    int tong = 0;
    for (int i = 0; i < 2 * n - 1; i++)
    {
        tong += a[i];
    }
    cout << tong;
}
/*
5
1 3 4 6 8
*/