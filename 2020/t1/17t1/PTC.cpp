#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("PTC.inp", "r", stdin);
    int k;
    cin >> k;
    int a[k + 2];
    int max = 0, dem = 0;
    for (int i = 1; i <= k; i++)
    {
        cin >> a[i];
        if (a[i] > max)
            max = a[i];
    }
    int q[k + 1][max + 1];
    for (int i = 1; i <= k; i++)
    {
        for (int j = 1; j <= a[i]; j++)
        {
            cin >> q[i][j];
        }
    }
    for (int i = 1; i <= k; i++)
    {
        sort(q[i] + 1, q[i] + a[i] + 1);
    }
    for (int i = 1; i <= a[1]; i++)
    {
        int kiem = q[1][i];
        int dem = 0;
        for (int j = 2; j <= k; j++)
        {
            if (binary_search(q[j] + 1, q[j] + a[j] + 1, kiem) == true)
            {
                dem++;
            }
        }
        if (dem == k - 1)
        {
            cout << kiem;
            return 0;
        }
    }
    cout << "x";
}