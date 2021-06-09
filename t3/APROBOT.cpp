#include <bits/stdc++.h>
using namespace std;
#define fr first
#define se second
#define ss second.second
bool cmp(pair<int, pair<int, int>> x, pair<int, pair<int, int>> y)
{
    return x.second.first < y.se.fr;
}
bool cms(pair<int, pair<int, int>> x, pair<int, pair<int, int>> y)
{
    return x.first > y.first;
}
int findMinSwap(vector<int> arr, int n)
{
    vector<pair<int, int>> vec(n);
    for (int i = 0; i < n; i++)
    {
        vec[i].first = arr[i];
        vec[i].second = i;
    }
    sort(vec.begin(), vec.end());
    int ans = 0, c = 0, j;
    for (int i = 0; i < n; i++)
    {
        if (vec[i].second == i)
            continue;
        else
        {
            swap(vec[i].first, vec[vec[i].second].first);
            swap(vec[i].second, vec[vec[i].second].second);
        }
        if (i != vec[i].second)
            --i;
        ans++;
    }

    return ans;
}

int main()
{
    int n, k;
    cin >> n >> k;
    vector<pair<int, pair<int, int>>> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first;
        a[i].second.first = i;
    }
    int m = n / k;
    sort(a.begin(), a.end(), cms);
    int dem = 0;
    for (int i = 0; i < n; i++)
    {
        if (i % k == 0)
            dem++;
        a[i].second.second = dem;
    }
    sort(a.begin(), a.end(), cmp);
    vector<int> b(n);
    for (int i = 0; i < n; i++)
    {
        b[i] = a[i].ss;
    }
    cout << findMinSwap(b, n);
}
/*
6 2
7 3 2 5 9 1
*/