#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    sort(a.begin(), a.end(), greater<int>());
    sort(b.begin(), b.end(), greater<int>());
    int dem = 0;
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (j >= n)
            break;
        while (a[j] >= b[i])
        {
            j++;
            if (j >= n)
                break;
        }
        if (j < n && a[j] < b[i])
        {
            dem++;
            j++;
        }
    }
    cout << dem;
}