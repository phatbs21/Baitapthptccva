#include <bits/stdc++.h>
using namespace std;

#define ll long long

const ll INF = 2e18;
const int N = 10e5 + 4;

vector<vector<pair<ll, ll>>> a(N);
vector<ll> d(N, INF);
vector<bool> p(N, 0);
vector<ll> path;
void dijkstra(ll s)
{
    path.assign(N, -1);
    priority_queue<pair<ll, ll>> q;
    q.push({0, s});
    d[s] = 0;
    while (!q.empty())
    {
        ll u = q.top().second;
        q.pop();
        for (ll i = 0; i < a[u].size(); i++)
        {
            ll v = a[u][i].first;
            ll w = a[u][i].second;
            if (d[u] + w < d[v])
            {
                d[v] = d[u] + w;
                q.push({(-d[v]), v});
                path[v] = u;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll n, m;
    cin >> n >> m;
    for (ll i = 0; i < m; i++)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        a[x].push_back(make_pair(y, z));
        a[y].push_back(make_pair(x, z));
    }
    dijkstra(1);
    if (d[n] == INF)
        cout << "-1" << endl;
    else
    {
        stack<ll> s;
        ll k = n;
        while (k != -1)
        {
            s.push(k);
            k = path[k];
        }
        while (!s.empty())
        {
            cout << s.top() << " ";
            s.pop();
        }
        cout << endl;
    }
}
