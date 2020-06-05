#include <bits\stdc++.h>
using namespace std;
int a[1000];
int n;
int merge(int l, int m, int r)
{
    int nb = m - l + 1;
    int nc = r - m;
    int b[nb], c[nc];
    for (int i = 1; i <= nb; i++)
        b[i] = a[l + i - 1];
    for (int i = 1; i <= nc; i++)
        c[i] = a[m + i];
    int i = 1, j = 1, k = l - 1;
    while ((i <= nb) and (j <= nc))
    {
        if (b[i] < c[j])    
        {
            k++;
            a[k] = b[i];
            i++;
        }
        else
        {
            k++;
            a[k] = c[j];
            j++;
        }
    }
    while (i <= nb)
    {
        k++;
        a[k] = b[i];
        i++;
    }
    while (j <= nc)
    {
        k++;
        a[k] = c[j];
        j++;
    }
    return 0;
}
int mergesort(int l, int r)
{
    if (l >= r)
        return 0;
    int m = (l + r) / 2;
    mergesort(l, m);
    mergesort(m + 1, r);
    merge(l, m, r);
}
int main()
{
    auto start = chrono::steady_clock::now();
    freopen("thunghiem.inp", "r", stdin);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    mergesort(1, n);
    for (int i = 1; i <= n; i++)
        cout << a[i];

    auto end = chrono::steady_clock::now();
    auto diff = end - start;
    cout << "Runtime: " << chrono::duration<double>(diff).count() << " seconds" << endl;
}
