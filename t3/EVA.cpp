#include <bits/stdc++.h>
using namespace std;
int n, k, m;
vector<vector<int>> a;
map<int, bool> mp;
int bfs(int s)
{
    vector<bool> visit(n, false);
    queue<int> q;
    visit[s] = true;
    q.push(s);
    int dem = -1;
    int temp = -1;
    vector<int> level(n);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        if (temp == u)
            dem++;
        if (mp[u] == true)
            return level[u];
        for (int i = 0; i < a[u].size(); i++)
        {
            int v = a[u][i];
            if (visit[v] == false)
            {
                visit[v] = true;
                level[v] = level[u] + 1;
                q.push(v);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    a.resize(n);
    for (int i = 0; i < k; i++)
    {
        int temp;
        cin >> temp;
        temp--;
        mp[temp] = true;
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        tmp1--;
        tmp2--;
        a[tmp1].push_back(tmp2);
        a[tmp2].push_back(tmp1);
    }
    for (int i = 0; i < n; i++)
    {
        cout << bfs(i) << " ";
    }
}