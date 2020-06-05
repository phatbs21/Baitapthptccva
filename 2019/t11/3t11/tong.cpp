#include <bits\stdc++.h>
using namespace std;
int main()
{
    freopen("tong.inp", "r", stdin);
    freopen("tong.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n / 2; i++)
    {
        int tong = i;
        for (int j = i + 1; j <= n / 2 + 1; j++)
        {
            tong = tong + j;
            if (tong == n)
            {
                cout << "1";
                return 0;
            }
            if (tong > n)
            {
                break;
            }
        }
    }
    cout << "-1";
}