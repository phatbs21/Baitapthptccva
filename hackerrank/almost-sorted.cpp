#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[i] = x;
        b[i] = x;
    }
    sort(b.begin(), b.end());
    int vt1, vt2, dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            dem++;
            if (dem == 1)
                vt1 = i;
            else
                vt2 = i;
        }
    }
    if (dem == 2)
    {
        cout << "yes\nswap " << vt1 + 1 << " " << vt2 + 1;
        return 0;
    }
    if (dem > 2)
    {
        reverse(a.begin() + vt1, a.begin() + vt2 +1);
    }

    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            cout << "no\n";
            return 0;
        }
    }
    cout << "yes\nreverse " << vt1 + 1 << " " << vt2 + 1;
}