#include <bits\stdc++.h>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int x[1000];
    for (int i = 0; i <= k; i++)
    {
        x[i] = i;
    }
    int i, j;
    while (1 == 1)
    {
        for (int m = 1; m <= k; m++)
            cout << x[m];
        cout << endl;
        i = k;
        while (x[i] == (n - k + i))
        {
            i--;
        }
        if (i == 0)
            break;
        x[i]++;
        for (j = i + 1; j <= k; j++)
        {
            x[j] = x[j - 1] + 1;
        }
    }
}
