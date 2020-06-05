#include <iostream>
using namespace std;
int n;
int c;
int a[20000][20000];
int gan(int k)
{
    c = 1;
    k = n - 1;
    for (int i = 1; i <= (n + 1) / 2; i++)
    {
        for (int h = i; h < i + k; h++)
        {
            if (c > n * n)
                break;
            a[i][h] = c;
            c++;
        }
        for (int h = i; h < i + k; h++)
        {
            if (c > n * n)
                break;
            a[h][n + 1 - i] = c;
            c++;
        }
        for (int h = n + 1 - i; h > n + 1 - k - i; h--)
        {
            if (c > n * n)
                break;
            a[n + 1 - i][h] = c;
            c++;
        }
        for (int h = n + 1 - i; h > n + 1 - k - i; h--)
        {
            if (c > n * n)
                break;
            a[h][i] = c;
            c++;
        }
        k -= 2;
    }
    if (n % 2 == 1)
    {
        a[(n + 1) / 2][(n + 1) / 2] = n * n;
    }
    return 0;
}

int main()
{
    cin >> n;
    gan(n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
