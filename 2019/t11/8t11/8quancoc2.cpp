#include <bits\stdc++.h>
using namespace std;
int n, x[10], dem = 0;
bool d[10], c1[10], c2[10];
void viet()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << (x[i] == j ? "H" : "0");
        }
        cout << endl;
    }
    cout << endl;
}
int thu(int i)
{
    if (i > n)
    {
        viet();
        dem++;
        return 0;
    }
    for (int k = 1; k <= n; k++)
    {
        if ((d[k] == false) && (c1[i - k + n] == false) && (c2[i + k] == false))
        {
            x[i] = k;
            d[k] = true;
            c1[i - k + n] = true;
            c2[i + k] = true;
            thu(i + 1);
            d[k] = false;
            c1[i - k + n] = false;
            c2[i + k] = false;
        }
    }
    return 0;
}
int main()
{
    cin >> n;
    for (int i = 0; i <= n; i++)
    {
        d[i] = false;
        c1[i] = false;
        c2[i] = false;
    }
    thu(1);
    cout << dem;
}