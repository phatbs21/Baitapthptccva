#include <bits\stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, a[50], t, k;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++)
    {
        k = i;
        t = a[i];
        while ((k > 0) && (a[k - 1] > t))
        {
            a[k] = a[k - 1];
            k--;
        }
        a[k] = t;
        cout << t << " " << k << endl;
    }
}