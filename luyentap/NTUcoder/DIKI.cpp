#include <iostream>
#include <algorithm>
using namespace std;
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    long long n, m, a[100000];
    bool check = false;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        if (binary_search(a + 1, a + n + 1, a[i] + m))
        {
            cout << a[i] << " " << a[i] + m;
            check = true;
            break;
        }
    }
    if (!check)
        cout << -1;
}
