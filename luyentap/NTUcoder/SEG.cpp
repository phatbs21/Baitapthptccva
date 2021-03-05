#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a)
        cin >> i;
    int kq = 0;
    for (int i = *max_element(a.begin(), a.end()); i <= accumulate(a.begin(), a.end(), 0); i++)
    {
        int dem = 0, tong = 0;
        for (int j = 0; j < n; j++)
        {
            tong += a[j];
            if (tong == i)
            {
                dem++;
                tong = 0;
            }
            else if (tong > i)
                break;
        }
        kq = max(kq, dem);
    }
    cout << kq;
}