#include <bits/stdc++.h>
using namespace std;

int binarySearch(int a[], int d, int c, int x)
{
    if (c >= d)
    {
        int g = d + (c - d) / 2;
        if (a[g] == x)
            return g;
        if (a[g] > x)
            return binarySearch(a, d, g - 1, x);
        return binarySearch(a, g + 1, c, x);
    }
    return -1;
}

int main(void)
{
    int k;
    cin >> k;
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int result = binarySearch(a, 1, n, k);
    (result == -1) ? cout << "Khong tim thay"
                   : cout << "Vi tri: " << result;
    return 0;
}