#include <bits/stdc++.h>
using namespace std;
vector<vector<pair<int, int>>> a;
const int N = 100005;
vector<int> d, path;
int n;
void dijkstra(int s)
{
    path.assign(n + 1, -1);
    d.assign(n + 1, INT_MAX);
    priority_queue<pair<int, int>> q;
    q.push({0, s});
    d[s] = 0;
    while (!q.empty())
    {
        int u = q.top().second;
        q.pop();
        for (int i = 0; i < a[u].size(); i++)
        {
            int v = a[u][i].first;
            int w = a[u][i].second;
            if (d[u] + w < d[v])
            {
                d[v] = d[u] + w;
                q.push({(-d[u]), v});
                path[v] = u;
            }
        }
    }
}
int main()
{
    int k;
    cin >> n >> k;
    vector<int> luu(k);
    for (int i = 0; i < k; i++)
        cin >> luu[i];
    int m;
    cin >> m;
    a.resize(n + 1);
    for (int i = 0; i < m; i++)
    {
        int temp1, temp2;
        cin >> temp1 >> temp2;
        a[temp1].push_back(make_pair(temp2, 1));
        a[temp2].push_back(make_pair(temp1, 1));
        //cout << "succesful";
    }
    dijkstra(1);
    for (int i = 1; i <= n; i++)
    {
        int minn = INT_MAX;
        for (int j = 0; j < k; j++)
        {
            if (d[luu[i]] - d[i] <= 0)
                minn = min(d[luu[j]] - d[i], minn);
        }
        cout << minn << " ";
    }
}