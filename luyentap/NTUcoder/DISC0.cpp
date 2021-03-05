#include <bits/stdc++.h>
using namespace std;
#define concac                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);                       \
    cout.tie(0);

int main()
{
    concac int n, m;
    cin >> n >> m;
    vector<bool> a(n + 1, false);
    vector<int> luu, d(n + 10), b(n);
    deque<int> q;
    for (int i = 1; i <= n; i++)
    {
        q.push_front(i);
    }
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        b[i] = x;
        q.push_back(x);
    }
    while (!q.empty())
    {
        if (a[q.back()] == false)
        {
            a[q.back()] = true;
            luu.push_back(q.back());
            cout << q.back() << " ";
        }
        q.pop_back();
    }
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        d[luu[i]] = n - i - 1;
        cout << d[luu[i]] << " ";
    }
    cout << "\n";
    for (int i = 0; i < m; i++)
    {
        cout << b[i] << " ";
    }
    cout << "\n";
    for (int i = 0; i < m; i++)
    {
        cout << d[b[i]] << " ";
    }
}
