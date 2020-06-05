#include <bits/stdc++.h>
using namespace std;

int a[500000], b[500000];
int main()
{
    int n, s = 0;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cin >> b[i];
    }
    sort(a, a + n);
    sort(b, b + n);
    for (int i = 0; i < n; i++)
    {
        if (a[i] > b[i - 1])
            s += (b[i] - a[i]);
        if (a[i] <= b[i - 1] && b[i] >= b[i - 1])
            s += (b[i] - b[i - 1]);
    }
    cout << s;
}