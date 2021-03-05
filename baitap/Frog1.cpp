#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int h[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> h[i];
    int f[100001];
    memset(f, 0, sizeof(f));
    f[1] = 0;
    f[2] = abs(h[1] - h[2]);
    for (int i = 3; i <= n; i++)
    {
        f[i] = min(f[i - 1] + abs(h[i] - h[i - 1]), f[i - 2] + abs(h[i] - h[i - 2]));
    }
    cout << f[n];
}