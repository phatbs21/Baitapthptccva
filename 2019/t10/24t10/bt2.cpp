#include <bits\stdc++.h>
using namespace std;
int main()
{
    int x = 0, n;
    cin >> n;
    int a[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        x = x ^ a[i];
    }
    cout << x;
}