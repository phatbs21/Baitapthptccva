#include <bits\stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[n + 1];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n + 1);
    for (int i = 0; i < n; i++)
        if (a[i] != i)
        {
            cout << i;
            return 0;
        }
    cout << "khong tim thay";
}