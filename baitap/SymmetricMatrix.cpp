#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int a1, a2, a3, a4;
        bool check = false;
        for (int i = 1; i <= n; i++)
        {
            cin >> a1 >> a2 >> a3 >> a4;
            if (a2 == a3)
                check = true;
        }
        if (m % 2 != 0)
        {
            cout << "No"
                 << "\n";
        }
        else
        {
            if (check == true)
                cout << "YES"
                     << "\n";
            else
                cout << "NO"
                     << "\n";
        }
    }
    return 0;
}
