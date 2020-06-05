#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //freopen("caitui.inp", "r", stdin);
    long long int n, w;
    long long int i, j;

    //stack<int> kq;
    cin >> n >> w;
    long long int m[n + 10], v[n + 10];
    long long int f[n + 10][w + 10];
    for (i = 1; i <= n; i++)
    {
        cin >> m[i] >> v[i];
    }
    for (j = 0; j <= w; j++)
    {
        f[0][j] = 0;
    }
    for (i = 0; i <= n; i++)
    {
        f[i][0] = 0;
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= w; j++)
        {
            if (m[i] <= j)
            {
                f[i][j] = max((f[i - 1][j - m[i]] + v[i]), (f[i - 1][j]));
            }
            else
            {
                f[i][j] = f[i - 1][j];
            }
        }
    }
    cout << f[n][w] << endl;
    /*
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
    return 0;*/
}
