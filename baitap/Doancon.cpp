#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    int Max = a[1], vt1 = 1, vt2 = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (a[j] - a[i] > Max)
            {
                Max = a[j] - a[i];
                vt1 = i + 1;
                vt2 = j;
            }
        }
    }
    cout << Max << "\n"
         << vt1 << " " << vt2;
}
