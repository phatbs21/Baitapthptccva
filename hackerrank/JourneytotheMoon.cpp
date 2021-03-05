#include <bits/stdc++.h>
using namespace std;
vector<vector<long long int>> a;
vector<bool> visit;
long long int dem = 0;
void dfs(long long int v)
{
    visit[v] = true;
    dem++;
    for (auto &i : a[v])
    {
        if (visit[i] != true)
        {
            dfs(i);
        }
        visit[v] = true;
    }
}
 int main()
{
    long long int n, p;
    cin >> n >> p;
    a.resize(n);
    visit.assign(n, false);
    for (long long int i = 0; i < p; i++)
    {
        long long int x, y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    long long int j = 0;
    long long int mang[300001];
    for (long long int i = 0; i < n; i++)
    {
        if (visit[i] == false)
        {
            dem = 0;
            dfs(i);
            mang[j] = dem;
            j++;
        }
    }
    long long int totalWays = n * (n - 1) / 2;
    long long int sameWays = 0;
    for (long long int i = 0; i < j; i++)
    {
        sameWays = sameWays + (mang[i] * (mang[i] - 1) / 2);
    }
    cout << (totalWays - sameWays) << endl;
}