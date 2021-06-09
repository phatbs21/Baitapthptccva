#include <bits/stdc++.h>
using namespace std;
vector<int> d, path;
vector<vector<pair<int, int>>> a;

void dijkstra(int s, int c)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    d[s] = 0;
    path[s] = s;
    q.push({0, s});
    long long w, tmp, k, xx;

    while (!q.empty())
    {
        int u = q.top().second;
        //cout << u << " ";
        int du = q.top().first;
        q.pop();
        if (d[u] != du)
        {
            continue;
        }
        //13 5 10 9 5 10 10 4 13 12 4 9 10 10 25
        //13 5 10 4 13 9 5 10 10 12 4 9 12 4 9 10 10 3 12 10 10 10 3 65
        for (int i = 0; i < a[u].size(); i++)
        {
            int v = a[u][i].first;
            cout << v << " ";
            int w = a[u][i].second;
            if (w <= c && w > 0)
            {
                if (d[u] + w <= c)
                {
                    tmp = d[u] + w;
                    if (d[v] > tmp)
                    {
                        d[v] = tmp;
                        q.push({d[v], v});
                    }
                }
                else if (c > 2 * w) // nhieu lan
                {
                    xx = (d[u] + w - c) / (c - 2 * w) - 1;
                    xx = max(xx, (long long)1);
                    for (k = xx; k <= xx + 10; ++k)
                    {
                        tmp = d[u] + w - k * (c - 2 * w);
                        if (tmp >= w && tmp <= c)
                        {
                            tmp = tmp + k * c;
                            if (d[v] > tmp)
                            {
                                d[v] = tmp;
                                q.push({d[v], v});
                            }
                        }
                    }
                }
            }
            // cout << w << " ";
            //9 5 8 4 3 7
            //9 4 5 8 3 3 7 2 6 1
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("NK05DSRT.inp", "r", stdin);
#endif
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;
        path.assign(n + 1, -1);
        a.clear();
        a.resize(n + 1);
        d.assign(n + 1, k);
        for (int i = 0; i < m; i++)
        {
            int xx, xy, ww;
            cin >> xx >> xy >> ww;
            a[xx].push_back({xy, ww});
            a[xy].push_back({xx, ww});
        }
        dijkstra(n, k);
        std::cout << d[1];
    }
}