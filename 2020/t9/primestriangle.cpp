#include <bits/stdc++.h>
using namespace std;
#define INF 10000000
int nto[INF + 1];

struct xuli
{
    int x, d, y;
};
bool cmp(xuli X, xuli Y)
{
    if ((X.x) > (Y.x))
        return (X.x) < (Y.x);
    return (X.x) < (Y.x);
}
bool cmp2(xuli X, xuli Y)
{
    if ((X.d) > (Y.d))
        return (X.d) < (Y.d);
    return (X.d) < (Y.d);
}
void ktra()
{
    nto[0] = -1, nto[1] = -1;
    int vt = 0;
    for (int i = 2; i <= INF; i++)
    {
        if (nto[i] == 0)
        {
            nto[i] = ++vt;
            for (int j = i * 2; j <= INF; j += i)
                nto[j] = -1;
        }
    }
}

int main()
{
    ktra();
    int t;
    cin >> t;
    xuli a[t + 1];
    for (int i = 1; i <= t; i++)
    {
        int n;
        cin >> n;
        a[i].x = n;
        a[i].d = i;
    }
    sort(a + 1, a + t + 1, cmp);
    for (int i = 1; i <= t; i++)
    {
        if (a[i].x== 2) 
        {
            a[i].x=0;
            a[i].y=1;
            continue;
        }
        if (nto[a[i].x] == -1)
        {
            a[i].x = -1;
            a[i].y = -1;
            continue;
        }
        int temp = nto[a[i].x];
        a[i].x = nto[a[i].x];
        int tong = 0;
        int z = 1;
        a[i].x--;
        int tong2 = 0;
        while (a[i].x >= 0)
        {
            tong++;
            a[i].x = a[i].x - tong;
        }
        for (int p = 1; p <= tong - 1; p++)
        {
            tong2 += p;
        }
        a[i].x = tong - 1; //a[i].x += tong;    //ngang
        a[i].y = temp % tong2;
    }
    sort(a + 1, a + t + 1, cmp2);
    for (int i = 1; i <= t; i++)
    {
        if (a[i].x != -1)
            cout << a[i].x + 1 << " " << a[i].y  << "\n";
        else
        {
            cout << -1 << "\n";
        }
    }
}