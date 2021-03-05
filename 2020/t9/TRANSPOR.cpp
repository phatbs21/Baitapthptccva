#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m, n;
    cin >> m >> n;
    vector<int> c(m);
    for (int i = 0; i < m; i++)
    {
        cin >> c[m];
    }
    vector<int> w(n);
    for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
    sort(c.begin(), c.end(), greater<int>());
    vector<bool> d(n, false);
    for (int i = 0; i < m; i++)
    {
        if (c[i] > 0)
            for (int j = 0; j < n; j++)
            {
                if (c[i] - w[j] >= 0 && d[j] != true)
                    c[i] -= w[j];
            }
    }
    for (int i = 0; i < n; i++)
    {
        if (d[i] == false)
        {
            cout << "-1";
            return 0;
        }
    }
}