#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("Og")
#pragma GCC push_options
#pragma GCC pop_options
bool ngto[100000005];
queue<int> q;
bool nto(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}
void sangnguyento(int n)
{
    if (n > 10000000)
        n = 10000000;
    memset(ngto, true, n + 1);
    ngto[0] = ngto[1] = false;
    for (int p = 2; p * p <= n; p++)
    {
        if (ngto[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                ngto[i] = false;
        }
    }
}
void uoc(int n)
{
    vector<int> v;
    for (int i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (n / i == i)
                q.push(i);
            else
            {
                q.push(i);
                v.push_back(n / i);
            }
        }
    }
    for (int i = v.size() - 1; i >= 0; i--)
        q.push(v[i]);
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("PASS.INP", "r", stdin);
    freopen("PASS.OUT", "w", stdout);
    int n;
    cin >> n;
    if (n == 0 || n == 1)
    {
        cout << 0 << " " << 0;
        return 0;
    }
    int dem = 0;
    long long int tong = 0;
    if (nto(n))
    {
        tong += n;
        dem++;
        cout << 1 << " " << n;
        return 0;
    }
    sangnguyento(n / 2 + 3);
    uoc(n);
    while (q.size() != 0)
    {
        if (ngto[q.front()] == true)
        {
            dem++;
            tong += q.front();
        }
        q.pop();
    }
    cout << dem << " " << tong;
}
