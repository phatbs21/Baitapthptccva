#include <bits\stdc++.h>
using namespace std;
int main()
{
    int n, k;
    int tong;
    cin >> n >> k;
    int a[n];
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        tong = 0;
        for (int j = i; j <= n; j++)
        {
            tong = tong + a[j];
            if (tong == k)
            {
                cout << i << ".." << j; 
                return 0;
            }
        }
    }
    cout << "khong tim thay";
}