#include <bits/stdc++.h>
using namespace std;
 int main()
{
    long long int t;
    cin >> t;
    while (t--)
    {
        long long int n;
        cin >> n;
        long long int i = 0;
        long long int tong = 0;
        long long int dem = 0;
        while (tong <= n)
        {
            dem++;
            i++;
            tong += i;
            // cout << tong << "-";
        }
        if (tong - i == n)
        {
            dem--;
            cout << dem << endl;
            continue;
        }
        /*
        if (n - tong - i > tong - n)
        {
            dem--;
            long long int q = n - (tong - i);
            cout << dem + q * 2 << endl;
            continue;
        }
        else
        {
            long long int q = tong - n;
            cout << q * 2 + dem << endl;
        }
        */
        cout << min(dem - 1 + (n - (tong - i)) * 2, dem + (tong - n) * 2) << endl;
        //cout << dem << "*" << endl;
    }
}