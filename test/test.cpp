#include <iostream>
using namespace std;
int n, tong, cheochinh, cheophu;
int a[21][21];
int main()
{
    freopen("test.INP", "r", stdin);
    // freopen("BAI3.OUT", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            tong += a[i][j];
        }
        cheochinh += a[i][i];
        cheophu += a[i][n - i + 1];
    }
    if (tong % n != 0)
    {
        cout << "F";
        return 0;
    }
    else
        tong /= n;
    for (int i = 1; i <= n; i++)
    {
        int t = 0;
        for (int j = 1; j <= n; j++)
            t += a[i][j];
        if (t != tong)
        {
            cout << "F";
            return 0;
        }
    }
    for (int j = 1; j <= n; j++)
    {
        int t = 0;
        for (int i = 1; i <= n; i++)
            t += a[i][j];
        if (t != tong)
        {
            cout << "F";
            return 0;
        }
    }
    cout<<cheochinh<<" ";
    if (cheophu == cheochinh)
        cout << "T";
    else
        cout << "F";
    return 0;
}
