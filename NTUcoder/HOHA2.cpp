#include <iostream>
#include <math.h>
using namespace std;
#define ll long long int
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n, a = 1;
    cin >> n;
    for (int i = 2; i <= sqrt(n); i++)
        if (n % i == 0)
            a = a + i + n / i;
    if (a == n)
        cout << "YES";
    else
        cout << "NO";
}