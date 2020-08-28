#include <bits/stdc++.h>
using namespace std;
#define lli long long

int n, k;
int a[1000], L[100], R[100];

void xuli()
{
    deque<int> q;
    for (int i = 1; i <= n; ++i)
    {
        while (!q.empty() && a[q.back()] >= a[i])
        {
            q.pop_back();
        }
        q.push_back(i);
        while (q.front() + k <= i)
            q.pop_front();
        if (i >= k)
            cout << a[q.front()] << "\n";
    }
}
int main()
{
    //freopen("test.inp","r",stdin);
    //freopen("test.out","w",stdout);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    xuli();

}