#include <bits\stdc++.h>
using namespace std;
void tinh(int a[], int x, int y, int &diff, int &maxv, int &minv)
{
    if (x == y)
    {
        diff = 0;
        maxv = minv = a[x];
    }
    else
    {
        int k = (x + y) / 2;
        int d1, max1, min1, d2, min2, max2;
        tinh(a, x, k, d1, max1, min1);
        tinh(a, k + 1, y, d2, max2, min2);
        minv = min(min1, min2);
        maxv = max(max1, max2);
        diff = max(max(d1, d2), max2 - min1);
    }
}
int main()
{
    freopen("dulieu.inp", "r", stdin);
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int d, m1, m2;
    tinh(a, 0, n - 1, d, m1, m2);
    cout << d;
}

