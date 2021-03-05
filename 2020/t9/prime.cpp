#include <bits/stdc++.h>
using namespace std;
int a[3001];
int main()
{
    int n, tong = 0;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] == 0)
        {
            for (int j = i; j <= n; j += i)
                a[j] += 1;
        }
        if (a[i] == 2)
            tong++;
    }
    cout << tong << endl;
}
