#include <bits/stdc++.h>
#include <stdlib.h>
using namespace std;
int min1(int a, int b, int c)
{
    return min(a, min(b, c));
}

int main()
{
    freopen("BDXAU.INP", "r", stdin);
    //freopen("BDXAU.out", "w", stdout);
    string x, y;
    x = " ertrtyui";
    y = " tyuhj";
    //getline(cin, x);
    //getline(cin, y);
    //cout << x << " " << y;
    int n = x.length();
    int m = y.length();
    int f[n + 1][m + 1];
    for (int i = 1; i <= n; i++)
        f[i][0] = i;
    for (int i = 1; i <= m; i++)
        f[0][i] = i;
    f[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (x[i] == y[j])
            {
                f[i][j] = f[i - 1][j - 1];
            }
            else
            {
                f[i][j] = min1(f[i - 1][j - 1] + 1, f[i][j - 1] + 1, f[i - 1][j] + 1);
            }
        }
    }
    string xau[2000];
    cout << f[n][m];
    int z = 1;
    int i = n, j = m;
    string so;
    while ((i > 0) && (j > 0))
    {
        if (x[i] == y[j])
        {
            i--;
            j--;
        }
        else
        {
            if (f[i][j] == f[i - 1][j - 1] + 1)
            {
                so = to_string(i);
                xau[z] = "R " + so + " " + y[j];
                z++;
                i--;
                j--;
            }
            else
            {
                if (f[i][j] = f[i][j - 1] + 1)
                {
                    so = to_string(i);
                    xau[z] = "I " + so + " " + y[j];
                    z++;
                    j--;
                }
                else
                {
                    so = to_string(i);
                    xau[z] = "D " + so;
                    z++;
                    i--;
                }
            }
        }
    }
    while (j > 0)
    {
        so = to_string(1);
        xau[z] = "I " + so + " " + y[j];
        z++;
        j--;
    }
    while (i > 0)
    {
        so = to_string(1);
        xau[z] = "D " + so;
        z++;
        i--;
    }
    for (int i = z; i >= 1; i--)
    {
        cout << xau[i] << endl;
    }
}

/* #include <bits/stdc++.h>
using namespace std;
struct kt
{

    int vt;
    char ch, tmp;
};

int main()
{
    string x = "ertrtyui", y = "tyuhj";
    int i, j, n, m, f[100][100];
    int t = 0;
    kt kq[100];
    //getline(cin,x);
    n = x.length();
    //getline(cin,y);
    m = y.length();
    for (i = 1; i <= n; i++)
    {
        f[i][0] = i;
    }
    for (j = 1; j <= m; j++)
    {
        f[0][j] = j;
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= m; j++)
        {
            if (x[i] == y[j])
                f[i][j] = f[i - 1][j - 1];
            else
                f[i][j] = min(f[i - 1][j - 1], min(f[i][j - 1], f[i - 1][j])) + 1;
        }
    }
    cout << f[n][m] << endl;
    i = n;
    j = m;
    while (i > 0 && j > 0)
    {
        if (x[i] == y[j])
        {
            i--;
            j--;
        }
        else
        {
            if (f[i][j] == f[i - 1][j - 1] + 1)
            {
                kq[t].vt = i;
                kq[t].ch = 'R';
                kq[t].tmp = x[i];
                i--;
                j--;
            }
            if (f[i][j] == f[i][j - 1] + 1)
            {
                kq[t].vt = i;
                kq[t].ch = 'I';
                kq[t].tmp = x[i];
                j--;
            }
            else
            {
                kq[t].vt = 1;
                kq[t].ch = 'D';
                kq[t].tmp = x[i];
                t++;
                i--;
            }
        }
    }
    while (j > 0)
    {
        kq[t].vt = 1;
        kq[t].ch = 'I';
        kq[t].tmp = x[i];
        t++;
        j--;
    }
    while (i > 0)
    {
        kq[t].vt = 1;
        kq[t].ch = 'D';
        kq[t].tmp = x[i];
        t++;
        i--;
    }
    for (int i=t;i>=0;i--)
    {
        cout<<kq[i].ch<<" "<<kq[i].vt<<" "<<kq[i].tmp<<endl;
    }
}
*/