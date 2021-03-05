#include <bits/stdc++.h>
using namespace std;
bool collinear(int x1, int y1, int x2,
               int y2, int x3, int y3)
{
    int a = x1 * (y2 - y3) +
            x2 * (y3 - y1) +
            x3 * (y1 - y2);

    if (a == 0)
        return true;
    else
        return false;
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
    }
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                if (collinear(a[i], b[i], a[j], b[j], a[k], b[k]) == true)
                {
                    cout << "Yes";
                    return 0;
                }
            }
        }
    }
    cout << "No";
}
