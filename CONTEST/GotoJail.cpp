#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a, b, dem = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        if (a == b)
            dem++;
        else
            dem = 0;
        if (dem == 3)
        {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
}