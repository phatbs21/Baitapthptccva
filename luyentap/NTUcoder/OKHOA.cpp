#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long int a = 0, b = 0;
    for (int i = n - 1; i > 0; i--)
    {
        b++;
        a += b * i;
    }
    cout << a + n;
}
