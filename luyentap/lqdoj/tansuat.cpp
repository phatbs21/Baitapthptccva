#include <bits/stdc++.h>

using namespace std;
int A[300005], n, k;
double f[300005];

bool check(double mid)
{
    for (int i = 1; i <= n; ++i)
        f[i] = f[i - 1] + (A[i] - mid);
    double minn = 0;
    for (int i = k; i <= n; ++i)
    {
        minn = min(minn, f[i - k]);
        if (f[i] >= minn)
            return true;
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        cin >> A[i];
    double L = 0, R = 1000000;
    while (R - L > 1e-7) 
    {
        double mid = (L + R) / 2;
        if (check(mid))
            L = mid;
        else 
            R = mid;
    }
    cout << setprecision(6) << fixed << L;
    return 0;
}