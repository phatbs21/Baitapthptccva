#include <bits/stdc++.h>
using namespace std;
bool compareInterval(int i1, int i2)
{
    return ((i2 | i1)-i1<(i1 | i2)-i2);
}
int main()
{
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i=1;i<n;i++)
    {
        for (int j=i+1;j<=n;j++)
        {
            if (((a[i]|a[j])-a[j])<((a[j]|a[i])-a[i]))
            swap(a[i],a[j]);
        }
    }
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
}