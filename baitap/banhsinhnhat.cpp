#include <bits/stdc++.h>
using namespace std;
int main()
{
    int l, n;
    cin >> l >> n;
    int p[n + 1], k[n + 1];
    int a[n + 1];
    static bool d[1001];
    static int b[1001];
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i] >> k[i];
        a[i] = k[i] - p[i];
    }
    int z = 1;
    int max = a[1];
    for (int i = 2; i <= n; i++)
        if (max < a[i])
        {
            max = a[i];
            z = i;
        }
    cout << z << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = p[i]; j <= k[i]; j++)
        {
            if (d[j] == false)
            {
                b[i]++;
                d[j] = true;
            }
        }
    }
    z = 1;
    max = b[1];
    for (int i = 2; i <= n; i++)
        if (max < b[i])
        {
            max = b[i];
            z = i;
        }
    cout << z;
}