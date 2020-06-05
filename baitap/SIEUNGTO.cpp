#include <bits/stdc++.h>
using namespace std;
long long int c[6] = {1, 2, 3, 5, 7, 9}, n, x[100000], dem = 0, z[100000];
int snt(int s)
{
    if (s < 2)
        return 0;

    for (int i = 2; i <= sqrt(s); i++)
    {
        if (s % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int ghepso(int h)
{
    int m = 0;
    for (int j = 1; j <= h; j++)
    {
        m = m * 10 + x[j];
    }
    return m;
}
void thu(int i)
{
    if (i > n)
    {
        if (snt(ghepso(n)) == 1)
        {
            dem++;
            z[dem] = ghepso(n);
        }
    }
    else
    {
        for (int v = 0; v <= 5; v++)
        {
            if (snt(ghepso(i - 1) * 10 + c[v]) == 1)
            {
                x[i] = c[v];
                thu(i + 1);
            }
        }
    }
}
int main()
{
    freopen("SIEUNGTO.INP", "r", stdin);
    freopen("SIEUNGTO.OUT", "w", stdout);
    cin >> n;
    thu(1);
    cout << dem << endl;
    for (int i = 1; i <= dem; i++)
        cout << z[i] << " ";
}
