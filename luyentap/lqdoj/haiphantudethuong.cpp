#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<pair<int, int>> maxx(n + 1), minn(n + 1);
    maxx[n - 1].first = a[n - 1];
    maxx[n - 1].second = n - 1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (maxx[i + 1].first < a[i])
        {
            maxx[i].first = a[i];
            maxx[i].second = i;
        }
        else
        {
            maxx[i].first = maxx[i + 1].first;
            maxx[i].second = maxx[i + 1].second;
        }
    }
    minn[0].first = a[0];
    minn[0].second = 0;
    for (int i = 1; i < n; i++)
    {
        if (minn[i - 1].first > a[i])
        {
            minn[i].first = a[i];
            minn[i].second = i;
        }
        else
        {
            minn[i].first = minn[i - 1].first;
            minn[i].second = minn[i - 1].second;
        }
    }
    int x, y, z = INT_MIN;
    for (int i = 0; i < n - 1; i++)
    {
        int t = maxx[i + 1].first - minn[i].first;
        if (t > z)
        {
            z = t;
            x = maxx[i + 1].second;
            y = minn[i].second;
        }
    }
    cout << y+1 << " " << x+1 << "\n"
         << z;
}