#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, dem = 0;
    cin >> n;
    int a[n], b[n];
    memset(b, 0, sizeof(b));
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if ((b[a[i]] == 0))
            dem++;
        b[a[i]] = 1;
    }
    cout << dem;
}