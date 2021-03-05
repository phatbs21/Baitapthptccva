#include <bits/stdc++.h>
using namespace std;
#define NAME "Energy"
#define tocdo cout << "Time " << clock() / (double)1000 << " sec"
ifstream fi(NAME ".inp");
ofstream fo(NAME ".out");

int main()
{
    int n, k, x, y;
    fi >> n;
    int64_t ans = 0;
    priority_queue<int64_t> a, p;
    for (int i = 0; i < 2 * n; i++)
    {
        fi >> x >> y;
        if (x >= y)
        {
            ans += y;
            a.push(x - y);
        }
        else
        {
            ans += x;
            p.push(y - x);
        }
    }
    x = a.size();
    k = (n > x) ? x : n;
    for (int i = 0; i < k; i++)
    {
        x = a.top();
        ans += x;
        a.pop();
    }
    x = p.size();
    k = (n > x) ? x : n;
    for (int i = 0; i < k; i++)
    {
        x = p.top();
        ans += x;
        p.pop();
    }
    fo << ans;
    tocdo;
}
