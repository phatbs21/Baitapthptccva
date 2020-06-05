#include <bits\stdc++.h>
using namespace std;
bool kt(int a, int b, int c)
{
    if ((a < b + c) && (b < c + a) && (c < b + a))
        return true;
    return false;
}
int main()
{
    int n;
    cin >> n;
    int a[n + 1];
    int dem = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n - 2; i++)
    {
        for (int j = i + 1; j <= n - 1; j++)
        {
            for (int k = j + 1; k <= n; k++)
            {
                if (kt(a[i], a[j], a[k]) == true)
                    dem++;
            }
        }
    }
    cout << dem + 1;
}