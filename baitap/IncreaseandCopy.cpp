#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int dm = 0;
        while (n != 0)
        {
            dm++;
            n = 1;
        }
        cout << dm << "\n";
    }
}