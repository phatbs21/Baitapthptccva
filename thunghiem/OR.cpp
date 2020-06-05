#include <bits/stdc++.h>
using namespace std;
bool kt(long long int a[], long long int n, long long int tong)
{
    for (long long int i = 1; i <= n; i++)
        for (long long int j = i + 1; j <= n; j++)
            if (a[i] + a[j] == tong)
                return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("CAPGAO.inp", "r", stdin);
    freopen("CAPGAO.out", "w", stdout);
    long long int n, m;
    cin >> m >> n;
    long long int w[m + 1], a[n + 1];
    for (long long int i = 1; i <= m; i++)
    {
        cin >> w[i];
    }
    for (long long int i = 1; i <= n; i++)
    {
        cin >> a[i];
        bool stop = false;
        for (long long int j = 1; j <= m; j++)
        {
            if (w[j] == a[i])
            {
                cout << 1;
                stop = true;
                break;
            }
        }
        if (stop == true)
        {
            continue;
        }
        if (kt(w, n, a[i]))
        {
            cout << 1;
        }
        else
        {
            cout << 0;
        }
    }
}