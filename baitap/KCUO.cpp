#include <bits/stdc++.h>
using namespace std;
char A[101][101];
int main()
{
    int n;
    cin >> n;
    int x = 1;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= (n - x) / 2; ++j)
        {
            cout << "*";
        }
        for (int k = 0; k < x; ++k)
        {
            cout << "D";
        }

        for (int j = x + (n - x) / 2 + 1; j <= n; ++j)
        {
            cout << "*";
        }
        if (n / 2 >= i)
            x += 2;
        else
            x -= 2;
        cout << endl;
    }
}
