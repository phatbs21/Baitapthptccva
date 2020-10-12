#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int &i : a)
            cin >> i;
        a.push_back(INT_MAX);
        a[n] = INT_MAX;
        sort(a.begin(), a.end());
        int dem = 0, tong = 0;
        for (int i = 0; i <= n; i++)
        {
            tong++;
            if (tong == a[i])
            {

                tong = 0;
                dem++;
            }
        }
        cout << dem << "\n";
    }
}