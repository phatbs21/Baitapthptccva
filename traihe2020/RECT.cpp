#define taskname "RECT"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;
using lli = long long;
const int maxN = 5e5 + 1;

int m, n, h[maxN], L[maxN], R[maxN];

void ReadInput()
{
    cin >> m >> n;
    for (int i = 1; i <= n; ++i)
        cin >> h[i];
}

lli Solve()
{
    stack<int> S;
    for (int i = 1; i <= n; ++i)
    {
        while (!S.empty() && h[S.top()] >= h[i])
            S.pop();
        L[i] = S.empty() ? 0 : S.top();
        S.push(i);
    }
    while (!S.empty())
        S.pop();
    for (int i = n; i >= 1; --i)
    {
        while (!S.empty() && h[S.top()] >= h[i])
            S.pop();
        R[i] = S.empty() ? n + 1 : S.top();
        S.push(i);
    }
    lli res = 0;
    for (int i = 1; i <= n; ++i)
    {
        lli temp = lli(h[i]) * (R[i] - L[i] - 1);
        if (temp > res)
            res = temp;
    }
    return res;
}

void Flip()
{
    for (int i = 1; i <= n; ++i)
        h[i] = m - h[i];
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(taskname ".INP", "r", stdin);
    freopen(taskname ".OUT", "w", stdout);
    ReadInput();
    lli res1 = Solve();
    Flip();
    lli res2 = Solve();
    cout << max(res1, res2);
}