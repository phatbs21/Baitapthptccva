#include <iostream>
using namespace std;
int main()
{
    int n, m;
    cin >> m;
    for (int j = 1; j <= m; j++)
    {
        cin >> n;
        int m = n, i = 0;
        while (m > 0)
        {
            i = i * 10 + m % 10;
            m = m / 10;
        }
        if (i == n)
            cout << n << " ";
    }
    return 0;
}