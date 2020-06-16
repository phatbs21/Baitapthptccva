#include <iostream>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long int tong = 0, n, v, a[1000000] = {0}, m, z = 0;
    cin >> n >> v;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += a[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        while ((z <= n) && (a[i] - a[z] >= v))
        {
            z++;
        }
        tong += z;
    }
    cout << tong;
}
