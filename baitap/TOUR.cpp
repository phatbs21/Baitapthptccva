//http://ntucoder.net/Problem/Details/3308
#include <bits/stdc++.h>
using namespace std;
int stt = 0, dem = 0;
int number[200002], low[200002];
vector<int> q[200002];

int dfs(int u, int p)
{
    stt++;
    number[u] = stt;
    low[u] = INT_MAX;
    for (int v = 0; v < q[u].size(); v++)
    {
        int z = q[u][v];
        if (z != p)
        {
            if (number[z] > 0)
            {
                low[u] = min(low[u], number[z]);
            }
            else
            {
                dfs(z, u);
                low[u] = min(low[u], low[z]);
            }
        }
    }
    //Trường hợp number[v]>0 thì u ở trong chu trình, do đó đỉnh u loại trừ (không tăng biến dem)
    if (number[u] < low[u])
    {
        dem++;
    }
    return 0;
}

int main()
{
    int n, a, b, m;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;
        q[a].push_back(b);
        q[b].push_back(a);
    }
    memset(number, 0, sizeof(number));
    cin >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> a >> b;
        q[a].push_back(n + 1);
        q[n + 1].push_back(a);
        q[b].push_back(n + 1); // taoj tehem bien gia
        q[n + 1].push_back(b);
    }
    dfs(1, 0);
    cout << dem;
}
