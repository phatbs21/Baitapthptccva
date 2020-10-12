#include <bits/stdc++.h>
using namespace std;
#define NAME "TEMPLE"
#define all(x) x.begin(), x.end()
ifstream fi(NAME ".inp");
ofstream fo(NAME ".out");
const int INF = (1e9 + 1e3);
int main()
{
    int m, n, k;
    fi >> n >> m >> k;
    vector<string> s(n);
    vector<int> xx(k), yy(k);
    int sx = -1, sy = -1, fx = -1, fy = -1;
    for (int i = 0; i < n; i++)
    {
        fi >> s[i];
        for (int j = 0; j < m; j++)
        {
            if (s[i][j] == 'S')
            {
                sx = i;
                sy = j;
            }
            if (s[i][j] == 'F')
            {
                fx = i;
                fy = j;
            }
        }
    }
    for (int i = 0; i < k; i++)
    {
        fi >> xx[i] >> yy[i];
        xx[i]--;
        yy[i]--;
    }

    auto check = [&](int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m && s[x][y] != '#';
    };
    int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
    vector<vector<int>> d(n, vector<int>(m, INF));

    auto bfs = [&](int x, int y) // hàm loang theo chiều rộng
    {
        for (int i = 0; i < n; i++)
            fill(all(d[i]), INF);
        d[x][y] = 0;
        queue<pair<int, int>> que;
        que.push({x, y});
        while (que.size())
        {
            int x = que.front().first;
            int y = que.front().second;
            que.pop();
            for (int i = 0; i < 4; i++)
            {
                if (check(x + dx[i], y + dy[i]) && d[x + dx[i]][y + dy[i]] > d[x][y] + 1)
                {
                    d[x + dx[i]][y + dy[i]] = d[x][y] + 1;
                    que.push({x + dx[i], y + dy[i]});
                }
            }
        }
    };
    bfs(sx, sy);
    if (k == 0)
    {
        if (d[fx][fy] == INF)
            d[fx][fy] = -1;
        fo << d[fx][fy] << "\n";
        return 0;
    }
    vector<vector<int>> dp(k, vector<int>(4, INF));
    for (int i = 0; i < 4; i++)
    {
        if (check(xx[0] + dx[i], yy[0] + dy[i]))
        {
            dp[0][i] = d[xx[0] + dx[i]][yy[0] + dy[i]];
        }
    }
    for (int i = 0; i + 1 < k; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (check(xx[i] + dx[j], yy[i] + dy[j]))
            {
                bfs(xx[i] + dx[j], yy[i] + dy[j]);
                for (int q = 0; q < 4; q++)
                {
                    if (check(xx[i + 1] + dx[q], yy[i + 1] + dy[q]))
                    {
                        dp[i + 1][q] = min(dp[i + 1][q], dp[i][j] + d[xx[i + 1] + dx[q]][yy[i + 1] + dy[q]]);
                    }
                }
            }
        }
    }
    bfs(fx, fy);
    int ans = INF;
    for (int i = 0; i < 4; i++)
        if (check(xx[k - 1] + dx[i], yy[k - 1] + dy[i]))
            ans = min(ans, dp[k - 1][i] + d[xx[k - 1] + dx[i]][yy[k - 1] + dy[i]]);
    if (ans == INF)
        ans = -1;
    fo << ans << "\n";
}