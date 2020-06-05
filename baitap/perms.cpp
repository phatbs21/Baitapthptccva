#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, dem = 1;
    cin >> n;
    int day[10];
    for (int i = 1; i <= n; ++i)
    {
        day[i] = i;
        dem = dem * i;
    }
    cout << dem << endl;
    do
    {
        for (int i = 1; i <= n; ++i)
        {
            cout << day[i];
        }
        cout << endl;
    } while (next_permutation(day + 1, day + n + 1));
}
