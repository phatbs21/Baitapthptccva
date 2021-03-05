#include <iostream>
using namespace std;
#define lli long long int
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    lli m, n, t, tong = 0;
    cin >> m >> n >> t;
    for (int i = 1; i <= n; i++)
    {
        if (i % m == 0)
            i++;
        tong += t;
    }
    cout << tong;
}
