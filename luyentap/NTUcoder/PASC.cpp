#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long a[50][50], n;
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        a[i][0] = 1;
        a[i][i] = 1;
    }
    for (int i = 2; i <= n; i++)
        for (int j = 1; j < i; ++j)
        {
            a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
        }
    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = 0; j <= i; ++j)
            cout << a[i][j] << " ";
        cout << endl;
    }
}
