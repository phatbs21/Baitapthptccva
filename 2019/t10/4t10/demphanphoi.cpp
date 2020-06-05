#include <bits\stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n], c[n];
    for (int i = 1; i <= n; i++)
    {
        c[i] = 0;
        cin >> a[i];
    }
    int max = a[1];
    for (int i = 1; i <= n; i++)
    {
        c[a[i]]++;
        if (a[i] > max)
            max = a[i];
    }
    for (int k = 0; k <= max; k++)
    {
        for (int i = 1; i <= c[k]; i++)
            cout << k << " ";
    }
}