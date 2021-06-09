#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[100001];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int flag = a[0] % 2;
    for (int i = 1; i < n; i++)
    {
        if (a[i] % 2 != flag && i != 1)
        {
            cout << a[i];
            return 0;
        }
        if (i == 1 && a[i] % 2 != flag)
        {
            cout << a[0];
            return 0;
        }
    }
    cout << a[0];
}