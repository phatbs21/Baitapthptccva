#include <bits/stdc++.h>
using namespace std;
const int N = 3000000;
#define ll unsigned long long
bool isPrime[N];
vector<int> Prime;
int k, test, d;
ll n;
void khoitao()
{
    for (int i = 2; i < N; i++)
        isPrime[i] = 1;
    isPrime[0] = isPrime[1] = 0;
    for (int i = 2; i * i < N; i++)
        if (isPrime[i])
            for (int j = i * i; j < N; j += i)
                isPrime[j] = 0;
    for (int i = 0; i < N; i++)
        if (isPrime[i])
            Prime.push_back(i);
    d = Prime.size();
}

void kt()
{
    ll res = 0;
    for (int i = 0; i < d - k + 1; i++)
    {
        ll s = 1;
        for (int j = i; j < i + k; j++)
            s *= Prime[j];
        if (s > n)
            break;
        else
            res = max(res, s);
    }
    if (res != 0)
        cout << res;
    else
        cout << -1;
}

int main()
{
    freopen("BAI1.INP", "r", stdin);
    freopen("BAI1.OUT", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    khoitao();
    cin >> n >> k;
    kt();
    cout << endl;
}