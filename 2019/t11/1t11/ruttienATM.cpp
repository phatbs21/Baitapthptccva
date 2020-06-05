#include <iostream>
using namespace std;
int main()
{
    int n, k;
    cin >> n >> k;
    int a[n];
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int s = 0, dem = 0;

    int i = n;
    while (s != k)
    {
        s = s + a[i];
        dem++;
        if (s > k)
        {
            s -= a[i];
            i--;
            dem--;
        }
    }
    cout << dem;
    return 0;
}
