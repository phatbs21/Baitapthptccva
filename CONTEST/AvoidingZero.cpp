#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, tong = 0;
        cin >> n;
        vector<int> a(n);
        for (auto &i : a)
        {
            cin >> i;
            tong += i;
        }
        if (tong == 0)
        {
            cout << "NO"
                 << "\n";
            continue;
        }
        int soam = 0, soduong = 0;
        int tongam = 0, tongduong = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] > 0)
            {
                soduong++;
                tongduong += a[i];
            }
            else
            {
                soam++;
                tongam += a[i];
            }
        }
        if (tongduong > abs(tongam))
            sort(a.begin(), a.end(), greater<int>());
        else
            sort(a.begin(), a.end());

        cout << "YES"
             << "\n";
        for (int i = 0; i < n; i++)
            cout << a[i] << " ";
        cout << "\n";
    }
}