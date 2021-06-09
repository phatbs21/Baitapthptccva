#include <bits/stdc++.h>
using namespace std;

 int main()
{
    double t, d;
    long long int n, k;
    cin >> n >> k;
    vector<long long int> a(n + 1);
    for (long long int i = 1; i <= n; i++)
        cin >> a[i];
    for (long long int i = 1; i <= n - k; i++)
    {
        for (long long int j = i; j <= n; j++)
        {
            t = t + a[j];
            if (j - i + 1 >= k)
                d = max(d, t / (j - i + 1));
        }
        t = 0;
    }
    cout << setprecision(6) << fixed << d;
}