#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n, a = 0;
    cin >> n;
    while (n != 0)
    {
        a = a + n % 10;
        n = n / 10;
    }
    if (a % 10 == 9)
        cout << "YES";
    else
        cout << "NO";
}