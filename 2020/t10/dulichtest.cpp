#include <bits/stdc++.h>
using namespace std;
int N, T, v;
vector<int> w, t, kq;
vector<vector<int>> a;
int Max = 0;
void dfs()
int main()
{
    freopen("dulich.inp", "r", stdin);
    cin >> N >> T >> v;
    t.resize(N);
    for (auto &i : t)
        cin >> i;
    a.resize(N);
    int z, x, c;
    while (cin >> z >> x >> c)
    {
        z--;
        x--;
        w.push_back(c);
        a[z].push_back(x);
        a[x].push_back(z);
    }
    int q = w.size();
    for (int i = 0; i < N; i++)
    {
        bfs(i);
    }
}