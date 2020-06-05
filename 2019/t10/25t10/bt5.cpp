#include <bits\stdc++.h>
using namespace std;
int main()
{
    int x[1000], i, n, k;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        x[i] = 0;
    }
    while (x[0] != 1)
    {
        for (i = 1; i <= n; i++)
        {
            cout << x[i];
        }
        cout << endl;
        k = n;
        while (x[k] == 1)
        {
            x[k] = 0;
            k--;
        }
        x[k] = 1;
    }
}
