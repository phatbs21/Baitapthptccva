#include <bits/stdc++.h>
int c[6] = {1, 2, 3, 5, 7, 9}, n, x[1000];
using namespace std;
int snt(int s)
{
    if (s < 2)
        return 0;

    for (int i = 2; i <= sqrt((float)s); i++)
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
            cout << ghepso(n);
        }
        cout << endl;
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
    cin >> n;
    thu(1);
}