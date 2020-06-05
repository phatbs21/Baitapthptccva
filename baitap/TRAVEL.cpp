#include <iostream>
#include <cstdio>
using namespace std;
long long int n, s;
long long int a[10002];
bool f[10002] = {0};
long long int sum = 0;
long long int dem = 0;
bool q = false, p = false;
void visit(long long int u)
{
    if (q == false && f[u] == 0)
    {
        f[u] = 1;
        sum += a[u];
        if (sum == s)
        {
            q = true;
            dem++;
            if (p == false)
                for (long long int i = 1; i <= n; i++)
                    f[i] = 0;
            sum = 0;
            return;
        }
        for (long long int v = u; v <= n; v++)
        {
            if (f[v] == 0 && sum + a[v] <= s)
            {
                visit(v);
            }
            else
            {
                if (sum + a[v] > n && f[v] == 0)
                {
                    p = true;
                    sum -= a[u];
                    f[u] = 0;
                    v--;
                }
            }
        }
    }
    else
    {
        return;
    }
}
int main()
{
    freopen("TRAVEL.INP", "r", stdin);
    freopen("TRAVEL.OUT", "w", stdout);
    cin >> n;
    cin >> s;
    for (long long int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    long long int i = 1;
    while ((i <= n))
    {
        sum = 0;
        q = false;
        visit(i);
        i++;
    }
    cout << dem << endl;
}
