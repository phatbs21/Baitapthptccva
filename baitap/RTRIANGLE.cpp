#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int n, n1 = 0, n2 = 0;
    cin >> n;
    while (n1 < n)
    {
        n2++;
        n1 += n2;
    }
    if (n1 == n)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}
