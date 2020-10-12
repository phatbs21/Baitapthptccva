#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t, n, T;
    cin >> t;
    while (t--)
    {
        cin >> n >> T;
        int a[n], c = 0;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
        {
            if (a[i] > T / 2)
                cout << 0 << " ";
            else if (a[i] == T / 2 && T % 2 == 0 && c % 2 == 0)
            {
                cout << 1 << " ";
                c++;
            }
            else if (a[i] == T / 2 && T % 2 == 0 && c % 2 != 0)
            {
                cout << 0 << " ";
                c++;
            }
            else
                cout << 1 << " ";
        }
        cout << endl;
    }
    return 0;
}
