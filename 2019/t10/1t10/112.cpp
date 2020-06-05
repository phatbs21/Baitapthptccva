#include <bits\stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    int i = 1, j = 1, tong = a[1];
    while (j <= n)
    {
        if (tong == k)
        {
            cout << i << ".." << j;
            return 0;
        }
        if (tong > k)
        {
            tong = tong - a[i];
            i++;
        }
        else
        {
            j++;
            tong = tong + a[j];
        }
    }
    cout << "khong tim thay";
}