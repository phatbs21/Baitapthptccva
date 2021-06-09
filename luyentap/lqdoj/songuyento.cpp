#include <bits/stdc++.h>
using namespace std;
#define ll unsigned long long int
vector<bool> prim;

void checkso(ll l, ll r)
{
    ll dem = 0;
    vector<bool> isPrime(r - l + 1, true); // x là số nguyên tố khi và chỉ khi isPrime[x - l] == true
    for (ll i = 2; i * i <= r; ++i)
    {
        for (ll j = max(i * i, ((l + i - 1) / i * i)); j <= r; j += i)
        {
            isPrime[j - l] = false;
        }
    }

    if (1 >= l)
    { // Xét riêng trường hợp số 1
        isPrime[1 - l] = false;
    }

    for (ll x = l; x <= r; x++)
    {
        if (isPrime[x - l])
        {
            dem++;
        }
    }
    cout << dem << "\n";
}
int main()
{
    ll t;
    cin >> t;
    for (ll i = 0; i < t; i++)
    {
        ll x, y;
        cin >> x >> y;
        checkso(x, y);
    }
}