#include <bits/stdc++.h>
using namespace std;
int main()
{
    //freopen("caitui.inp", "r", stdin);
    int n, w;
    int m[100], v[100];
    int f[100][1000];
    stack<int> kq;
    cin >> n >> w;
    for (int i = 1; i <= n; i++)
    {
        cin >> m[i] >> v[i];
    }
    for (int j = 0; j <= w; j++)
    {
        f[0][j] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        f[i][0] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            if (m[i] > j)
            {
                f[i][j] = f[i - 1][j];
            }
            else
            {
                f[i][j] = max(f[i - 1][j - m[i]] + v[i], f[i - 1][j]);
            }
        }
    }
    cout << f[n][w] << endl;
    int j = w;
    for (int i = n; i > 0; i--)
    {
        if (f[i][j] != f[i - 1][j])
        {
            kq.push(i);
            j = j - m[i];
        }
    }
    while (!kq.empty())
    {
        cout << kq.top() << " ";
        kq.pop();
    }
    return 0;
}
