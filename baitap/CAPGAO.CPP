#include <bits/stdc++.h>
using namespace std;
bool ttong(long long int a[], long long int n, long long int tong)
{
    unordered_set<long long int> q;
    for (long long int i = 0; i < n; i++)
    {
        long long int temp = tong - a[i];
        if (q.find(temp) != q.end())
            return true;
        q.insert(a[i]);
    }
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("CAPGAO.inp", "r", stdin);
    freopen("CAPGAO.out", "w", stdout);
    long long int m, n;
    cin >> m >> n;
    long long int w[m + 1], a[n + 1];
    for (long long int i = 0; i < m; i++)
    {
        cin >> w[i];
    }
    for (long long int i = 0; i < n; i++)
    {
        cin >> a[i];
        bool q = false;
        for (long long int j = 0; j < m; j++)
        {
            if (a[i] == w[j])
            {
                cout << 1;
                q = true;
                break;
            }
        }
        if (q == true)
        {
            continue;
        }
        if (ttong(w, m, a[i]) == true)
        {
            cout << 1;
        }
        else
        {
            cout << 0;
        }
    }
}