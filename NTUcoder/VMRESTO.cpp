#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    long int a[200][200], b[200], tong = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
            tong = tong + a[i][j];
            b[i] = b[i] + a[i][j];
        }
    tong = tong / (n - 1);
    for (int i = 1; i <= n; i++)
    {
        a[i][i] = tong - b[i];
        for (int j = 1; j <= n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}