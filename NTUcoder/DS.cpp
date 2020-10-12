#include <bits/stdc++.h>
using namespace std;
#define N 300000
vector<bool> used(N, false);
vector<int> g[N];
vector<int> nhiem;
void dfs(int u)
{
    nhiem.push_back(u);
    used[u] = true;
    for (auto v : g[u])
    {
        if (used[v] == false)
        {
            dfs(v);
        }
    }
    used[u] = true;
    return;
}
int main()
{
    int n, k;
    cin >> n >> k;
    k--;
    // số lượng người làm việc trong toà nhà và số hiệu của nhân viên đã nhiễm Ebola đầu tiên
    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            int temp;
            cin >> temp;
            temp--;
            g[i].push_back(temp);
        }
    }
    dfs(k);
    sort(nhiem.begin(), nhiem.end());
    cout << nhiem.size() << "\n";
    for (auto i : nhiem)
        cout << i + 1 << " ";
}