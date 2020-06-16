#include <iostream>
using namespace std;
    int a[7990];
int main()
{

    int n, tong = 0;
    long long int m;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> m;
        a[m - 10102010]++;
    }
    for (int i = 0; i < 7990; i++)
    {
        if (a[i] > 5)
        {
            tong += 100 + a[i] - 5;
        }
        else if (a[i] > 0)
        {
            tong += 100;
        }
    }
    cout << tong;
}