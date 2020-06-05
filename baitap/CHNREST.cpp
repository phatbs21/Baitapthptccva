#include <bits/stdc++.h>
using namespace std;
struct xuli
{
    int x, d;
};
bool cmp(xuli X, xuli Y)
{
    if ((X.x) > (Y.x))
        return (X.x) < (Y.x);
    return (X.x) < (Y.x);
}

int main()
{
    string s;
    int m, n;
    int b[100][100];
    int d[100];
    int tong = 0;
    memset(d, 0, 100);
    cin >> m >> n;
    xuli a[m + 1];
    for (int i = 1; i <= m; i++)
    {
        cin >> a[i].x;
        a[i].d = i;
    }
    cin.ignore();
    for (int i = 1; i <= n; i++)
    {
        getline(cin, s);
        istringstream is(s);
        int c, j = 1;
        while (is >> c)
        {
            b[i][j] = c;
            j++;
        }
        b[i][0] = j - 1;
    }
    int check = 0;
    sort(a + 1, a + m + 1, cmp);
    for (int i = 1; i <= m; i++)
    {
        check = 0;
        for (int j = 1; j <= n; j++)
        {
            int dem = 0;
            if (d[j] < 2)
                if (binary_search(b[j] + 1, b[j] + b[j][0] + 1, a[i].d))
                {
                    check++;
                    d[j]++;
                    dem++;
                }
            if (check == 1)
            {
                tong += dem * a[i].x;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (d[i] != 2)
        {
            cout << -1;
            return 0;
        }
    }
    cout << tong;
}