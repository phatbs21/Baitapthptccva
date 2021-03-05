#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int x, y;
    cin >> x >> y;
    for (int i = 1; i <= y / 5; i++)
    {
        for (int j = 1; j <= y / 3; j++)
        {
            for (int k = 1; k <= 3 * y; k++)
            {
                if ((i * 5 + j * 3 + k / 3 == y) && (i + j + k == x) && (k % 3 == 0))
                {
                    cout << i << " " << j << " " << k;
                    return 0;
                }
            }
        }
    }
    cout << "-1";
    return 0;
}
