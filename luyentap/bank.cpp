#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<vector<int>> a;
    int n;
    cin >> n;
    a.resize(4);
    for (int i = 1; i <= 3; i++)
        a[i].resize(n);
    for (int i = 1; i <= 3; i++)
    {
        string s;
        cin >> s;
        for (int j = 1; j <= n; j++)
        {
            a[i][j] = s[i - 1] - 48;
        }
    }
    int f[100][100];
    memset(f, 0, sizeof(f));
    int j = 1, i = 1;
    while (i < n)
    {
        int x = f[i][j];
        if (i == 1)
            x = max(x * 2 + f[i + 1][j], x * 2 + f[i][j + 1]);
        if (i == 2)
            x = max(max(x * 2 + f[i + 1][j], x * 2 + f[i - 1][j]), f[i][j - 1]);
        if (i == 3)
            x = max(f[i][j + 1] + x * 2, x * 2 + f[i - 1][j]);
    }
}