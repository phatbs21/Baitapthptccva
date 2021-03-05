#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, d, tong = 0;
    cin >> n >> d;
    while (n--)
    {
        long long int a, b;
        cin >> a >> b;
        if (sqrt(a * a + b * b) <= d)
        {
            tong++;
        }
    }
    cout << tong << endl;
}