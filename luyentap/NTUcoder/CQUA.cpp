#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, x, k = 0, h = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> x;
        if (x == 200)
            k++;
        else
            h++;
    }
    if (h == 0)
    {
        if (k % 2 == 0)
            cout << "YES";
        else
            cout << "NO";
    }
    else if (h % 2 == 0)
        cout << "YES";
    else
        cout << "NO";
}