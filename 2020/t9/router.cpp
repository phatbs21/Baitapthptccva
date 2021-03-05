#include <bits/stdc++.h>
using namespace std;
#define NAME "router"
#define ff first
#define ss second
typedef pair<int, int> pii;
ifstream fi(NAME ".inp");
ofstream fo(NAME ".out");
int main()
{
    int n, m, x, f2, f5, d, x0 = 1, y0 = 1;
    fi >> n >> m;
    vector<vector<pii>> b(n, vector<pii>(m));
    vector<vector<char>> c(n, vector<char>(m));
    vector<vector<pii>> dp(2, vector<pii>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            fi >> x;
            if (x == 0)
            {
                if (x0 < i)
                    x0 = i, y0 = j;
                b[i][j] = {40000, 40000};
                continue;
            }
            f2 = f5 = 0;
            while (x > 0)
            {
                if ((x & 1) == 0)
                    ++f2, x >>= 1;
                else
                    break;
            }
            while (x > 0)
            {
                if ((x % 5) == 0)
                    ++f5, x /= 5;
                else
                    break;
            }
            b[i][j] = {f2, f5};
        }
    }
    pii tl, td;
    dp[0][0] = b[0][0];
    c[0][0] = 'S';
    for (int j = 1; j < m; j++)
    {
        c[0][j] = 'L';
        dp[0][j].first = dp[0][j - 1].first + b[0][j].first;
        dp[0][j].second = dp[0][j - 1].second + b[0][j].second;
    }
    int u = 0, v = 1;
    for (int i = 1; i < n; i++)
    {
        dp[v][0].first += b[i][0].first;
        dp[v][0].second += b[i][0].second;
        c[i][0] = 'D';
        for (int j = 1; j <= m; j++)
        {
            tl.first = dp[v][j - 1].first + b[i][j].first;
            tl.second = dp[v][j - 1].second + b[i][j].second;
            td.first = dp[u][j].first + b[i][j].first;
            td.second = dp[u][j].second + b[i][j].second;
            if (min(tl.first, tl.second) <= min(td.first, td.second))
            {
                c[i][j] = 'L', dp[v][j] = tl;
            }
            else
                c[i][j] = 'D', dp[v][j] = td;
        }
        u ^= 1;
        v ^= 1;
    }
    x = min(dp[u][m - 1].first, dp[u][m - 1].second);
    string s, s0;
    if (x0 < n && x >= 1)
    {
        d = 1;
        s0 = "";
        for (int i = 0; i < x0; i++)
            s0 += 'D';
        for (int i = 0; i < y0; i++)
            s0 += 'L';
        for (int i = x0 + 1; i < n; i++)
            s0 += 'D';
        for (int i = y0 + 1; i < m; i++)
            s0 += 'L';
    }
    else
    {
        s0 = "Z";
    }
    if (x0 > n || x <= 1)
    {
        d = x;
        u = n - 1;
        v = m - 1;
        s = c[u][v];
        while (true)
        {
            if (c[u][v] == 'L')
                --v;
            else
                --u;
            if (u + v == 0)
                break;
            s += c[u][v];
        }
        reverse(s.begin(), s.end());
    }
    s = min(s, s0);
    fo << d << endl;
    fo << s;
    cout << "Time:" << clock() / (double)1000 << " sec";
}
