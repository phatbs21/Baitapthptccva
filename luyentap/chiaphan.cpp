#include <bits/stdc++.h>
using namespace std;
#define tocdo cout << "Time " << clock() / (double)1000 << " sec"

int main()
{
    freopen("chiaphan.inp", "r", stdin);
    int n;
    cin >> n;
    vector<int> a(n);
    int tong = 0;
    for (auto &i : a)
    {
        cin >> i;
        tong += i;
    }
    int dem = 0;
    int tong1 = 0;
    for (int i = 0; i < n - 3; i++)
    {
        tong1 += a[i];
        int tong2 = 0;
        for (int j = i + 1; j < n - 2; j++)
        {
            tong2 += a[j];
            int tong3 = 0;
            for (int k = j + 1; k < n - 1; k++)
            {
                tong3 += a[k];
                if (tong - tong1 - tong2 - tong3 == tong1 && tong1 == tong2 && tong3 == tong2)
                    dem++;
            }
        }
    }
    cout << dem << "\n";
    tocdo;
}