#include <bits/stdc++.h>
using namespace std;
#define on 1
//http://ntucoder.net/Problem/Details/3289
int main()
{
    int a[200001], d[200001];
    int n, q, u, maximum;
    memset(a, 0, sizeof(a));
    memset(d, 0, sizeof(d));
    cin >> n >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> u;
        a[u] = abs(a[u] - 1);
        d[1] = on;
        for (int i = 2; i <= n; i++)
        {
            if (a[i] == a[i - 1])
                d[i] = on;
            else
            {
                d[i] = d[i - 1] + 1;
            }
        }
        maximum = d[1];
        for (int i = 2; i <= n; i++)
        {
            maximum = max(maximum, d[i]);
        }
        cout << maximum << endl;
    }
}
