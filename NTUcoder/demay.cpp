#include <bits/stdc++.h>
using namespace std;
#define ll long long int
ll lt(ll a, ll b)
{
    if (b == 1)
        return a % 123456789;
    if (b == 0)
        return 1;
    ll c = lt(a, b / 2);
    if (b % 2)
        return c * c % 123456789 * a % 123456789;
    else
        return c * c % 123456789;
}

int main()
{
    long long n, tong;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    tong = lt(2, n - 1);
    cout << tong << endl;
}
