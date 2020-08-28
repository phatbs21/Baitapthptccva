#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Og")
#pragma GCC push_options
#pragma GCC pop_options
bool bc(int a, int b, int c)
{
    if (c % a == 0 && c % b == 0 && c % (a * 2) != 0 && c % (b * 2) != 0)
        return true;
    else
        return false;
}
int max(int a[], int n)
{
    int max = a[1];
    for (int i = 1; i <= n; i++)
        if (max < a[i])
            max = a[i];
    return max;
}
int main()
{
    int n;
    int m;
    cin >> n >> m;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int dem = 0;
    int c = max(a, n);
    int x;
    for (int i = c; i <= m; i++)
    {
        x = 0;
        for (int j = 1; j < n; j++)
        {
            if (bc(a[j] / 2, a[j + 1] / 2, i) == true)
            {
                x++;
         
            }
        }
        if (x == n - 1)
        {
            dem++;
        }
    }
    cout << dem;
}
