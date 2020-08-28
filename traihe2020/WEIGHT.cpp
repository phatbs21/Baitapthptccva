#define taskname "WEIGHT"
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <stack>

using namespace std;
using lli = long long;
const int maxN = 4e5 + 1;
int n, a[maxN], L[maxN], R[maxN];
lli res = 0;

void ReadInput()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
}

void CalLR()
{
    stack<int> S;
    for (int i = 1; i <= n; ++i)
    {
        while (!S.empty() && a[S.top()] > a[i])
            S.pop();
        L[i] = S.empty() ? 0 : S.top();
        S.push(i);
    }

    while (!S.empty())
        S.pop();

    for (int i = n; i >= 1; --i)
    {
        while (!S.empty() && a[S.top()] >= a[i])
            S.pop();
        R[i] = S.empty() ? n + 1 : S.top();
        S.push(i);
    }

    for (int i = 1; i <= n; ++i)
        res -= lli(a[i]) * (i - L[i]) * (R[i] - i);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen(taskname ".INP", "r", stdin);
    freopen(taskname ".OUT", "w", stdout);
    ReadInput();
    CalLR();
    for (int i = 1; i <= n; ++i)
        a[i] = -a[i];
    CalLR();
    cout << res;
}