#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    map<int, int> d;
    int temp2 = 0, temp1 = 0, x = 0, y = 0;
    d[a[0] % k]++;
    for (int i = 1; i < n; i++)
    {
        int du = a[i] % k;
        while (d[k - du] != 0 || (du == 0 && d[du] != 0))
        {
            d[a[temp2] % k]--;
            temp2++;
        }
        temp1++;
        d[du]++;
        if ((temp1 - temp2) > (y - x))
        {
            x = temp2;
            y = temp1;
        }
    }
    cout << y - x + 1 << "\n";
    for (int i = x; i <= y; i++)
        cout << i + 1 << " ";
}
